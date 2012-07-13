#include "clientfs.ih"

string ClientFS::genKey(size_t size) {
	AutoSeeded_RNG rng;
	PK_Encryptor_EME encryptor(*(d_conf->encPublicKey()), "EME1(SHA-256)");

	SecureVector<byte> key = rng.random_vec(size);

	return hexEncode(encryptor.encrypt(key, rng)) + ";keysign=" + createSignature(d_conf->signPrivateKey(), key);
}
