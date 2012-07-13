#ifndef SEEPOST_CLIENTCONNECTION_H
#define SEEPOST_CLIENTCONNECTION_H

#include <bobcat/clientsocket>
#include <bobcat/ifdstream>
#include <bobcat/ofdstream>

#include <string>
#include <botan/botan.h>
#include <botan/pubkey.h>
#include <botan/pbkdf2.h>
#include <botan/hmac.h>
#include <botan/sha160.h>

#include "../clientconfig/clientconfig.h"
#include "../connection/connection.h"

namespace SEEPost
{
	class ClientConnection: public connection
	{
			std::string d_hostname;
			FBB::ClientSocket d_conn;
			ClientConfig *d_conf;

		public:
			ClientConnection(std::string const &server, size_t port, ClientConfig *conf);
			~ClientConnection();
			int connect();
			
		private:
			bool handshake();
	};
}

#endif
