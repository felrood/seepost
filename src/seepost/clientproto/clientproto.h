#ifndef SEEPOST_CLIENTPROTO_H
#define SEEPOST_CLIENTPROTO_H

#include "../clientconfig/clientconfig.h"
#include "../clientconnection/clientconnection.h"
#include <botan/pubkey.h>

namespace SEEPost
{
	class ClientProto
	{
			ClientConnection *d_conn;
			
		public:
			ClientProto(ClientConnection *conn);
			
			void init();
			
			std::string getBlob(size_t num);
			void putBlob(size_t id, std::string blb);
			size_t length();
			std::vector<size_t> list();
			std::string peek();
			std::string peek(size_t num);
			void drop(size_t id);
			void send(std::string const &address, std::string const &msg);
			void del(size_t id);
			Botan::Public_Key *encpubkey(std::string const &address);
			Botan::Public_Key *signpubkey(std::string const &address);
	};
}

#endif
