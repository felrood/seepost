#include "clientapplication.ih"

void ClientApplication::retr() {

	size_t num_msgs = d_proto->length();

	if(num_msgs == 0) {
		cout << "No new messages" << endl;
		return;
	}

	size_t cnt = 0;

	for(size_t idx = 0; idx != num_msgs; ++idx) {
		string msg = d_proto->peek();

		// TODO drop after put
		d_proto->drop(0);

		string head = msg.substr(0, msg.find('\n'));
		string body_head = msg.substr(msg.find('\n')+1);
		string key_enc = body_head.substr(0, body_head.find('\n'));
		string body_enc = body_head.substr(body_head.find('\n')+1);

		map<string, string> kv_head=decodeKV(head);

		if(kv_head["from_server"].length() == 0 || kv_head["timestamp_server"].length() == 0) {
			cout << "Corrupted message retrieved, discarding" << endl;
			continue;
		}

		SecureVector<byte> enc_masterkey = hexDecodeSV(key_enc);

		PK_Decryptor_EME decryptor(*(d_conf->encPrivateKey()), "EME1(SHA-256)");

		SecureVector<byte> masterkey = decryptor.decrypt(enc_masterkey);

		SymmetricKey key = deriveKey("AES", masterkey, 32);
		InitializationVector iv = deriveKey("IV",   masterkey, 16);


		Pipe p(new Hex_Decoder);
		p.append(get_cipher("AES-256/CBC/PKCS7", key, iv, DECRYPTION));
		p.process_msg(body_enc);
		string body = p.read_all_as_string(Pipe::LAST_MESSAGE);

		body_head = body.substr(0, body.find('\n'));
		size_t fst = body.find('\n')+1;
		size_t lst = body.find_last_of('\n');
		string body_body = body.substr(fst, lst - fst);
		string digest = body.substr(body.find_last_of('\n')+1);

		map<string, string> kv_body = decodeKV(body_head);

		if(kv_body["from"].length() == 0 ||
		   kv_body["name"].length() == 0 ||
		   kv_body["subject"].length() == 0 ||
		   kv_body["timestamp"].length() == 0 ||
		   kv_body.find("from_server") != kv_body.end() ||
		   kv_body.find("timestamp_server") != kv_body.end())
		{
			cout << "Corrupted message received, discarding" << endl;
			continue;
		}



		string headers = encodeKV(kv_body);
		headers += ';' + encodeKV(kv_head) + ";status=U;prio=0";

		Public_Key *pk = d_proto->signpubkey(kv_body["from"]);
		if(verifySignature(pk, digest, body.substr(0, body.find_last_of('\n')))) {
			DateTime dt;
			headers += ";digest=" + digest + ";sign=OK;sign_verified="+dt.rfc2822();
		} else {
			cout << "Signature did NOT verify, discarding message.\n";
			continue;
		}

		d_fs->addMessage(headers, body_body);
		cnt++;
	}
	cout << "You have " << cnt << " new messages" << endl;
}
