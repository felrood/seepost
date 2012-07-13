#include "clientfs.ih"

bool ClientFS::open() {

	string blb;
	try {
		blb = d_proto->getBlob(0);
	} catch(FBB::Errno const &e) {
		return false;
	}
	
	map<string, string> config = decodeKV(blb);
	
	if(config["version"].at(0) != FS_VERSION) {
		string err("Wrong FS Version. Version ");
		err += config["version"] + " found, " + FS_VERSION + " supported.";
		throw FBB::Errno(0, err.c_str());
	}
	
	if(config["key"].length() == 0 || config["keysign"].length() == 0) {
		throw FBB::Errno(0, "No key or iv found in config");
	}

	PK_Decryptor_EME decryptor(*(d_conf->encPrivateKey()), "EME1(SHA-256)");

	SecureVector<byte> masterkey = decryptor.decrypt(hexDecodeSV(config["key"]));
	
	if(!verifySignature(d_conf->signPublicKey(), config["keysign"], masterkey)) {
		throw FBB::Errno(0, "FS signature is NOT correct. Someone is doing something nasty! (or you found a bug)");
	}
	
	d_fs_key = deriveKey("AES", masterkey, 32);
	d_fs_iv = deriveKey("IV",   masterkey, 16);
	
	return true;
}
