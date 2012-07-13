#ifndef SEEPOST_INTERSERVER_H
#define SEEPOST_INTERSERVER_H

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
	class InterServer
	{
			AccountStore *d_accountstore;
			ServerConfig *d_conf;
			size_t d_port;
			
		public:
			InterServer(size_t port, AccountStore *as, ServerConfig *conf);

			void operator()();
	};
}

#endif
