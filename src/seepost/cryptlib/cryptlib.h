#ifndef CRYPTLIB_H
#define CRYPTLIB_H
#include <string>
#include <iostream>
#include <botan/botan.h>
#include <botan/pubkey.h>

namespace CryptLib {
    std::string hash(std::string const &hash, std::string const &input);
    
    std::string hexEncode(std::string const &input);
    std::string hexEncode(Botan::SecureVector<Botan::byte> const &input);

    std::string hexDecode(std::string const &input);
    Botan::SecureVector<Botan::byte>hexDecodeSV(std::string const &input);

    bool verifySignature(Botan::Public_Key *pk, std::string const &digest, std::string const &message);
    bool verifySignature(Botan::Public_Key *pk, std::string const &digest, Botan::SecureVector<Botan::byte> const &message);
    std::string createSignature(Botan::Private_Key *pk, std::string const &message);
    std::string createSignature(Botan::Private_Key *pk, Botan::SecureVector<Botan::byte> const &message);

	Botan::SymmetricKey deriveKey(std::string const &param, Botan::SymmetricKey const &masterkey, size_t outputlength);

    std::string encryptSym(std::string const &algo, std::string const &key, std::string const &iv, std::string const &plaintext);
    std::string decryptSym(std::string const &algo, std::string const &key, std::string const &iv, std::string const &ciphertext);
    std::string decryptSym(std::string const &algo, std::string const &key, std::string const &iv, std::istream &ciphertext);
}

#endif
