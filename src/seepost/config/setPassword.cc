#include "config.ih"

void SEEPost::Config::setPassword(string const &password)
{
	d_password = password;
	d_needpassword = true;
}
