#include "config.ih"

namespace SEEPost {
	Config::Config(string const &filename, string const &password)
	{
		d_password = password;
		d_needpassword = true;
		d_filename = filename;
		//load();
	}
}

