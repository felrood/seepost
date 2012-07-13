#ifndef SEEPOST_ACCOUNT_H
#define SEEPOST_ACCOUNT_H
#include <string>
#include <simpleini/SimpleIni.h>
#include <iostream>
#include <botan/botan.h>
#include <botan/pkcs8.h>
#include <botan/rsa.h>
#include <botan/pem.h>
#include <botan/ber_dec.h>
#include <blobstore/blobstore.h>
#include <queue/queue.h>

namespace SEEPost { 
	class Account {

    	bool d_good;
        std::string d_name;
        std::string d_address;
		Botan::Public_Key *d_sign_pub;
		Botan::Public_Key *d_enc_pub;
		BlobStore d_blobstore;
		Queue d_inqueue;

		public:
			Account(std::string const &filename, std::string const &dir);
			Account(Account const &other) = delete;
			~Account();

            // getters
        	bool good() const {
                return d_good;
            }
			
			std::string name() const {
				return d_name;
			}

            std::string address() {
                return d_address;
            }
			
			Botan::Public_Key *signPublicKey() {
				return d_sign_pub;
			}
			
			Botan::Public_Key *encPublicKey() {
				return d_enc_pub;
			}
			
			SEEPost::BlobStore blobstore() {
				return d_blobstore;
			}

			SEEPost::Queue &inqueue() {
				return d_inqueue;
			}
	};
}
#endif
