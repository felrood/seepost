#ifndef SEEPOST_SERVERCONNECTION_H
#define SEEPOST_SERVERCONNECTION_H

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
	class ServerConnection: public connection
	{
			AccountStore *d_accountstore;
			Account *d_account;
			ServerConfig *d_conf;

		public:
			ServerConnection(FBB::SocketBase *sb, AccountStore *as, ServerConfig *conf);
			~ServerConnection();

			void operator()();

			void list();
			void get(size_t idx);
			void put(size_t idx, std::string data);
			void del(size_t idx);

			void send(std::string const &adress, std::string const &msg);

			void peek();
			void peek(size_t id);
			void drop(size_t id);
			void length();
			void encpubkey(std::string const &address);
			void signpubkey(std::string const &address);
			
		private:
			bool handshake();
			bool processCommand(std::string &cmd);
	};
}

#endif
