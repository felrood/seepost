#include "config.ih"

/*
 * Try to read an unencrypted keyfile
 */

bool SEEPost::Config::readPlain() {
	
	ifstream file(d_filename.c_str());
    if(!file.good()) {
        d_good = false;
        return false;
    }

	stringstream buffer;
	buffer << file.rdbuf();
	string buf = buffer.str();

	CSimpleIniA ini;
	
	if(tryIni(ini, buf)) {
		loadValues(ini);
	} else {
		d_needpassword = true;
	}
	
	return d_good;
}
