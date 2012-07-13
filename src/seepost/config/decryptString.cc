#include "config.ih"
#include <iostream>
#include <botan/botan.h>
#include "../cryptlib/cryptlib.h"

using namespace Botan;


string SEEPost::Config::decryptString(string const &ciphertext, string const &password) {
	if(ciphertext.substr(0, 8) != "Salted__") {
		//TODO exception throwen?
		d_good = false;
		return "";
	}

	string salt = ciphertext.substr(8, 8);

	string hash1=CryptLib::hash("MD5", password + salt);
	string hash2=CryptLib::hash("MD5", hash1 + password + salt);
	string hash3=CryptLib::hash("MD5", hash2 + password + salt);

	string crypt(CryptLib::decryptSym("AES-256/CBC/NoPadding", hash1 + hash2, hash3, ciphertext.substr(16)));

	return crypt;
}