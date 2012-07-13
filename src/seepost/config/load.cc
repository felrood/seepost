#include "config.ih"

/*
 * Load the keyfile
 */

bool SEEPost::Config::load() {
	
	if(d_needpassword) {
		readEncrypted();
	} else {
		readPlain();
	}
	
	return d_good;
}