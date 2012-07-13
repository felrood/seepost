#include "interserver.ih"

SEEPost::InterServer::InterServer(size_t port, AccountStore *as, ServerConfig *conf)
:
	d_port(port)
{
	d_accountstore = as;
	d_conf = conf;
}