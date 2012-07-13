#ifndef SEEPOST_KEYSERVER_H
#define SEEPOST_KEYSERVER_H

#include <string>
#include <bobcat/serversocket>
#include <bobcat/ifdstream>
#include <bobcat/ofdstream>
#include <botan/botan.h>
#include "../serverconfig/serverconfig.h"
#include "../connection/connection.h"

namespace SEEPost
{
	class KeyServer
	{
			ServerConfig *d_conf;
			size_t d_port;
			
		public:
			KeyServer(size_t port, ServerConfig *conf);

			void operator()();
	};
}

#endif
