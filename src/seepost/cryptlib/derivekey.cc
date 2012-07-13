#include "cryptlib.ih"
#include <memory>

SymmetricKey CryptLib::deriveKey(const string& param,
                        const SymmetricKey& masterkey,
                        size_t outputlength)
{
	std::auto_ptr<KDF> kdf(get_kdf("KDF2(SHA-1)"));
	return kdf->derive_key(outputlength, masterkey.bits_of(), param);
}