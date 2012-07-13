#include "cryptlib.ih"

string CryptLib::encryptSym(string const &algo, string const &keyStr, string const &ivStr, string const &plaintext) {
	SymmetricKey key(hexDecode(keyStr));
	InitializationVector iv(hexDecode(ivStr));

	Pipe encrypt(get_cipher(algo, key, iv, ENCRYPTION));

	encrypt.start_msg();
	encrypt.write(plaintext);
	encrypt.end_msg();

	return encrypt.read_all_as_string();
}
