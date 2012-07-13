#ifndef SEEPOST_INTERSERVERCONNECTION_H
#define SEEPOST_INTERSERVERCONNECTION_H

#include <string>
#include <bobcat/serversocket>
#include <bobcat/ifdstream>
#include <bobcat/ofdstream>
#include <botan/botan.h>
#include "../accountstore/accountstore.h"
#include "../serverconfig/serverconfig.h"
#include "../connection/connection.h"

namespace SEEPost
{
	class InterServerConnection: public connection
	{
			AccountStore *d_accountstore;
			ServerConfig *d_conf;
			Botan::Public_Key *d_otherserver_key;

		public:
			InterServerConnection(FBB::SocketBase *sb, AccountStore *as, ServerConfig *conf);

			void operator()();

			void send(std::string const &adress, std::string const &msg);
			void encpubkey(std::string const &address);
			void signpubkey(std::string const &address);
			
		private:
			bool handshake();
			bool processCommand(std::string &cmd);
	};
}

#endif
