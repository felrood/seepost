#include "config.ih"
#include <fstream>

namespace SEEPost {
	Config::Config(string const &filename)
		:
			d_needpassword(false),
			d_filename(filename)
       	{
			//load();
		}
}

