#ifndef SEEPOST_ACCOUNTSTORE_H
#define SEEPOST_ACCOUNTSTORE_H
#include <string>
#include <vector>
#include <simpleini/SimpleIni.h>
#include <iostream>
#include <botan/botan.h>
#include <botan/pkcs8.h>
#include <botan/rsa.h>
#include <botan/pem.h>
#include <botan/ber_dec.h>

#include <account/account.h>

namespace SEEPost {
	class AccountStore {

    	bool d_good;
	    std::string d_dir;
        std::vector<Account*> d_accounts;

		public:
			AccountStore(std::string const &dir);

            // getters
			bool good() const {
                return d_good;
            }
			
			std::string dir() {
				return d_dir;
			}

            std::vector<Account*> &accounts() {
                return d_accounts;
            }
	};
}
#endif
