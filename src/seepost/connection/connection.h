#ifndef _CONNECTION_H
#define _CONNECTION_H

#include <bobcat/clientsocket>
#include <bobcat/ifdstream>
#include <bobcat/ofdstream>

#include <string>
#include <botan/botan.h>
#include <botan/pubkey.h>
#include <botan/pbkdf2.h>
#include <botan/hmac.h>
#include <botan/sha160.h>

namespace SEEPost {
	class connection {
		protected:
			FBB::IFdStream *d_in;
			FBB::OFdStream *d_out;
			std::string d_session_param;
			Botan::Pipe *d_enc_in;
			Botan::Pipe *d_enc_out;
			bool d_use_enc;
			Botan::InitializationVector *d_iv;
			Botan::SymmetricKey *d_key;
		
			void DHKX(Botan::Public_Key *pubkey, Botan::Private_Key *privkey);
		public:
			int static const PROTOCOL_VERSION = 1;
			connection();
			~connection();
			std::string readmsg();
			void writemsg(std::string const &msg);
	};
}

#endif
