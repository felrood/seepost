#ifndef SEEPOST_INTERSERVERCLIENT_H
#define SEEPOST_INTERSERVERCLIENT_H

#include <bobcat/clientsocket>
#include <bobcat/ifdstream>
#include <bobcat/ofdstream>

#include <string>
#include <botan/botan.h>
#include <botan/pubkey.h>
#include <botan/pbkdf2.h>
#include <botan/hmac.h>
#include <botan/sha160.h>

#include "../connection/connection.h"

namespace SEEPost
{
	class InterServerClient: public connection
	{
			std::string d_hostname;
			std::string d_servername;
			std::string d_response;
			size_t d_port;
			FBB::ClientSocket *d_conn;
			Botan::Public_Key *d_public_key;
			Botan::Private_Key *d_private_key;

		public:
			InterServerClient(std::string const &server, size_t port, std::string &servername, Botan::Public_Key *pubkey, Botan::Private_Key *privkey);
			bool connect();
			bool send(std::string const &address, std::string const &msg);
			bool encpubkey(std::string const &address);
			bool signpubkey(std::string const &address);
			
			std::string response() {
				return d_response;
			}
			
		private:
			bool handshake();
	};
}

#endif
