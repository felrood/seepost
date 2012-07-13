#include "connection.ih"

void SEEPost::connection::DHKX(Public_Key *pub_key, Private_Key *priv_key)
{
	// Init encrypt and decrypt functions
	//Public_Key *pub_key = d_conf->serverPublicKey();
	PK_Encryptor_EME rsa_encryptor(*pub_key, "Raw");

	//Private_Key *priv_key = d_conf->encPrivateKey();
	PK_Decryptor_EME rsa_decryptor(*priv_key, "Raw");

	// generate a, p and g
	AutoSeeded_RNG rng;
	DL_Group shared_domain("modp/ietf/1024");

	DH_PrivateKey priv(rng, shared_domain);
	MemoryVector<byte> pub(priv.public_value());
	
	// A = g^a mod p
	PK_Key_Agreement ka(priv, "KDF2(SHA-256)");

	// Encrypt B
	SecureVector<byte> sb = rsa_encryptor.encrypt(pub, rng);

	size_t max = sb.size();

	// Send encrypted B
	for(size_t i = 0; i < max; ++i) {
		*d_out << sb[i];
	}
	*d_out << flush;
	
	// Recieve encrypted B
	MemoryVector<byte> B_enc;
	for(size_t i = 0; i < max; ++i) {
		byte f = d_in->get();
		B_enc.push_back(f);
	}

	// Decrypt B
	MemoryVector<byte> B = rsa_decryptor.decrypt(B_enc);

	// key = B^a mod p
	d_key = new SymmetricKey(ka.derive_key(32, B, d_session_param));

	//Debug::log << "Key: " << key.as_string() << endl;

	// Derive IV
	KDF *kdf = get_kdf("KDF2(SHA-256)");
	d_iv = new InitializationVector(kdf->derive_key(16, d_key->bits_of(), ""));

	//Debug::log << "IV: " << iv.as_string() << endl;

	d_enc_out = new Pipe(get_cipher("AES-256/CBC/PKCS7", *d_key, *d_iv, ENCRYPTION));
	d_enc_in = new Pipe(get_cipher("AES-256/CBC/PKCS7", *d_key, *d_iv, DECRYPTION));

	d_use_enc = true;
}
