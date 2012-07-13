#include "cryptlib.ih"

string CryptLib::createSignature(Private_Key *pk, string const &message) {
	AutoSeeded_RNG rng;
	PK_Signer signer(*pk, "EMSA4(SHA-256)");

	istringstream imsg(message);

	Botan::DataSource_Stream in(imsg);
	Botan::byte buf[4096] = { 0 };
	while(size_t got = in.read(buf, sizeof(buf)))
		signer.update(buf, got);

	return hexEncode(signer.signature(rng));
}