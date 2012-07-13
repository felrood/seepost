#include "config.ih"

/*
 * Try to parse and read an ini file. Will fail if its encrypted
 */

bool SEEPost::Config::tryIni(CSimpleIniA &ini, string const &data) {
	try {
		ini.SetMultiLine(true);
		int ret = ini.LoadData(data);
		
		if(ret != SI_OK) {
			d_good = false;
			return false;
		}

		int size = ini.GetSectionSize("account") + ini.GetSectionSize("server");

		d_good = (size > 0);
	} catch(Exception e) {
        cout << e.what() << endl;
		d_good = false;
	}
	
	return d_good;
}
