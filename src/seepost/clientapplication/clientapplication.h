#ifndef SEEPOST_CLIENTAPPLICATION_H
#define SEEPOST_CLIENTAPPLICATION_H

#include "../clientconfig/clientconfig.h"
#include "../clientconnection/clientconnection.h"
#include "../clientfs/clientfs.h"
#include "../clientproto/clientproto.h"

namespace SEEPost
{
	class ClientApplication
	{
			ClientConfig *d_conf;
			ClientConnection *d_conn;
			ClientFS *d_fs;
			ClientProto *d_proto;
			
		public:
			ClientApplication(ClientConfig *conf);
			
			void init();
			
			ClientConnection &conn() {
				return *d_conn;
			}

			ClientProto &proto() {
				return *d_proto;
			}
			
			ClientFS &fs() {
				return *d_fs;
			}
			
			ClientConfig &config() {
				return *d_conf;
			}

			void retr();
	};
}

#endif
