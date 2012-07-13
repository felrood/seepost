#include "cryptlib.ih"

string CryptLib::decryptSym(string const &algo, string const &keyStr, string const &ivStr, string const &ciphertext) {
	istringstream in(ciphertext);
	return decryptSym(algo, keyStr, ivStr, in);
}
