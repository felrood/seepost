#ifndef SEEPOST_KEYSERVERCONNECTION_H
#define SEEPOST_KEYSERVERCONNECTION_H

#include <string>
#include <bobcat/serversocket>
#include <bobcat/ifdstream>
#include <bobcat/ofdstream>
#include <botan/botan.h>
#include "../serverconfig/serverconfig.h"
#include "../connection/connection.h"

namespace SEEPost
{
	class KeyServerConnection: public connection
	{
			ServerConfig *d_conf;
			size_t static const PROTOCOL_VERSION = 1;
			
		public:
			KeyServerConnection(FBB::SocketBase *sb, ServerConfig *conf);

			void operator()();

			void get(std::string const &servername);
			
		private:
			bool handshake();
			bool processCommand(std::string &cmd);
	};
}

#endif
