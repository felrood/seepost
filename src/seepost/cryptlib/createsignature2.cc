#include "cryptlib.ih"

string CryptLib::createSignature(Private_Key *pk, SecureVector<byte> const &message) {
	AutoSeeded_RNG rng;
	PK_Signer signer(*pk, "EMSA4(SHA-256)");
	signer.update(message);

	return hexEncode(signer.signature(rng));
}