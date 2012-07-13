#include "command.ih"

bool Command::write(istringstream &stream, ClientApplication &app) {
    
	cout << "To: " << flush;
	string address;
	getline(cin, address);

	// TODO minder lelijke regexp maken
	if(!match_regex("^[[:alnum:]][[:alnum:]\\._]*@[[:alnum:]][[:alnum:]]*\\.[[:alnum:]][[:alnum:]]*$", address)) {
		cout << "Not a valid address" << endl;
		return true;
	}

	cout << "Subject: " << flush;
	string subject;
	getline(cin, subject);

	DateTime dt;

	string msg = "from=";
	msg += app.config().address() + ';';
	msg += "name=" + app.config().name() + ';';
	msg += "timestamp=" + dt.rfc2822() + ';';
	msg += "subject=" + subject + ";\n";

	cout << "Message: (end with EOF)" << endl;
	while(true) {
		string line;
		getline(cin, line);

		if(line == "EOF")
			break;

		msg += line + '\n';
	}
	
	AutoSeeded_RNG rng;

	// Create the RSA encryptor for the key
	Public_Key *pk_enc = app.proto().encpubkey(address);
	PK_Encryptor_EME encryptor(*pk_enc, "EME1(SHA-256)");

    SymmetricKey masterkey(rng, std::min<size_t>(32, encryptor.maximum_input_size()));
    SymmetricKey key = deriveKey("AES", masterkey, 32);
    SymmetricKey iv  = deriveKey("IV", masterkey, 16);

	SecureVector<byte> encrypted_key = encryptor.encrypt(masterkey.bits_of(), rng);
	
	// Do the encryption
	Pipe p(get_cipher("AES-256/CBC/PKCS7", key, iv, ENCRYPTION));
	p.append(new Hex_Encoder);
    p.process_msg(msg + '\n' + createSignature(app.config().signPrivateKey(), msg));

	// Create the message itself.
	// Format: <rsa_encrypted_key>\n<aes_encrypted_msg>
	string real_msg = hexEncode(encrypted_key) + '\n';
	real_msg += p.read_all_as_string(0);

	app.proto().send(address, real_msg);
	cout << "Message sent!" << endl;
	return true;
}
