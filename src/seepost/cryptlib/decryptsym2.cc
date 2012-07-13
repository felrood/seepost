#include "cryptlib.ih"


string CryptLib::decryptSym(string const &algo, string const &keyStr, string const &ivStr, istream &in) {
	SymmetricKey key(hexDecode(keyStr));
	InitializationVector iv(hexDecode(ivStr));

	Pipe decrypt(get_cipher(algo, key, iv, DECRYPTION));

	decrypt.start_msg();
	in >> decrypt;
	decrypt.end_msg();
	return decrypt.read_all_as_string(0);
}
