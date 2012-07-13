#ifndef SEEPOST_CLIENTFS_H
#define SEEPOST_CLIENTFS_H

#include <string>
#include <vector>
#include "../clientproto/clientproto.h"
#include "../clientconfig/clientconfig.h"

namespace SEEPost
{
	class ClientFS
	{
			ClientProto *d_proto;
			ClientConfig *d_conf;
			Botan::SymmetricKey d_fs_key;
			Botan::InitializationVector d_fs_iv;
		public:
			char static const FS_VERSION = '1';
			ClientFS(ClientProto *proto, ClientConfig *conf);
			void init();

			std::vector<std::string> list(size_t num);
			std::map<std::string, std::string> read(size_t id);

			std::string hexKey();
			std::string hexIV();
			
			void addMessage(std::string const &headers, std::string const &body);
			bool delMessage(size_t msg_id);
			void wipe();

			size_t spaceUsed();

			// Public for debugging			
			std::string getBlob(size_t num);

		private:
			std::string genKey(size_t size);

			void putBlob(size_t id, std::string blb);
			size_t nextMsgID();
			size_t nextInodeID();
			void initfs();
			bool open();
	};
}

#endif
