#ifndef SEEPOST_CLIENTCONFIG_H
#define SEEPOST_CLIENTCONFIG_H

#include <config/config.h>
#include <simpleini/SimpleIni.h>

namespace SEEPost {
	class ClientConfig : public Config {
        std::string d_name;
		std::string d_address;
		std::string d_server;
		int d_port;
		
		Botan::Private_Key *d_sign_priv;
		Botan::Private_Key *d_enc_priv;
		Botan::Public_Key *d_sign_pub;
		Botan::Public_Key *d_enc_pub;
		Botan::Public_Key *d_server_pub;

        public:
            ClientConfig() : Config() { };
            ClientConfig(std::string &file) : Config(file) { };
            ~ClientConfig();

            // getters
            Botan::Private_Key *signPrivateKey() {
				return d_sign_priv;
			}
			
			Botan::Private_Key *encPrivateKey() {
				return d_enc_priv;
			}
			
			Botan::Public_Key *signPublicKey() {
				return d_sign_pub;
			}
			
			Botan::Public_Key *encPublicKey() {
				return d_enc_pub;
			}
			
			Botan::Public_Key *serverPublicKey() {
				return d_server_pub;
			}
			
			std::string name() {
				return d_name;
			}
			
			std::string server() {
				return d_server;
			}
			
			std::string address() {
				return d_address;
			}
			
			int port() {
				return d_port;
			}
        private:
            virtual bool loadValues(CSimpleIniA &ini);
    };
}

#endif
