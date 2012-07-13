#ifndef SEEPOST_SERVERCONFIG_H
#define SEEPOST_SERVERCONFIG_H

#include <config/config.h>
#include <simpleini/SimpleIni.h>

namespace SEEPost {
	class ServerConfig : public Config {

        int d_port;
        std::string d_servername;
        Botan::Private_Key *d_sign_priv;
		Botan::Private_Key *d_enc_priv;
		Botan::Public_Key *d_sign_pub;
		Botan::Public_Key *d_enc_pub;
    
        public:
         
            ServerConfig() : Config() { };
            ServerConfig(std::string &file) : Config(file) { };
            ~ServerConfig();

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

            int port() {
                return d_port;
            }

            std::string &servername() {
            	return d_servername;
            }

        private:
               virtual bool loadValues(CSimpleIniA &ini);
    };
}

#endif
