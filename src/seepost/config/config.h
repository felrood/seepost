#ifndef SEEPOST_CONFIG_H
#define SEEPOST_CONFIG_H
#include <string>
#include <simpleini/SimpleIni.h>
#include <iostream>
#include <botan/botan.h>
#include <botan/pkcs8.h>
#include <botan/rsa.h>
#include <botan/pem.h>
#include <botan/ber_dec.h>

namespace SEEPost {
	class Config {

        protected:
    		bool d_good;
	    	bool d_needpassword;
	    	std::string d_password;
	    	std::string d_filename;

		public:
			Config();
			Config(std::string const &keyfile);
			Config(std::string const &keyfile, std::string const &password);

			bool load();
			void setKeyfile(std::string const &filename);
			void setPassword(std::string const &password);
			
            // getters
			bool needsPassword() {
				return d_needpassword;
			}

            bool good() const {
                return d_good;
            }
			
		private:
			bool readPlain();
			bool readEncrypted();
			virtual bool loadValues(CSimpleIniA &ini) = 0;
			bool tryIni(CSimpleIniA &ini, std::string const &data);
			std::string decryptString(std::string const &ciphertext, std::string const &password);
	};
}
#endif
