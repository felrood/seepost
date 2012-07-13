#include "keyserver.ih"

SEEPost::KeyServer::KeyServer(size_t port, ServerConfig *conf)
:
	d_port(port)
{
	d_conf = conf;
}