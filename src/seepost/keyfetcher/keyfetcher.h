#ifndef SEEPOST_KEYFETCHER_H
#define SEEPOST_KEYFETCHER_H

#include <string>
#include <bobcat/serversocket>
#include <bobcat/ifdstream>
#include <bobcat/ofdstream>
#include <botan/botan.h>

namespace SEEPost
{
	class KeyFetcher
	{
			Botan::Public_Key *d_pubkey;
			size_t static const PROTOCOL_VERSION = 1;

		public:
			bool fetchKey(std::string &server);
			Botan::Public_Key &pubkey() {
				return *d_pubkey;
			}
	};
}

#endif