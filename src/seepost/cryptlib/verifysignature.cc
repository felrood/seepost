#include "cryptlib.ih"

bool CryptLib::verifySignature(Public_Key *pk, string const &digest, string const &message) {
	istringstream imsg(message);

	PK_Verifier ver(*pk, "EMSA4(SHA-256)");
	DataSource_Stream in(imsg);
	byte buf[4096] = { 0 };
	while(size_t got = in.read(buf, sizeof(buf)))
		ver.update(buf, got);

	return ver.check_signature(hexDecodeSV(digest));
}

