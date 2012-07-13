#include "cryptlib.ih"

bool CryptLib::verifySignature(Public_Key *pk, string const &digest, SecureVector<byte> const &message) {
	PK_Verifier ver(*pk, "EMSA4(SHA-256)");
	ver.update(message);
	return ver.check_signature(hexDecodeSV(digest));
}

