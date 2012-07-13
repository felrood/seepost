#include "config.ih"

/*
 * Try to read an encrypted keyfile
 */

bool SEEPost::Config::readEncrypted() {
	
	ifstream file(d_filename.c_str());
    
    if(!file.good()) {
        d_good = false;
        return d_good;
    }

	stringstream buffer;
	buffer << file.rdbuf();
	string ciphertext = buffer.str();
	
	string plaintext = decryptString(ciphertext, d_password);
	
	CSimpleIniA ini;
	
	if(tryIni(ini, plaintext)) {
		loadValues(ini);
	}
	
	return d_good;
}
