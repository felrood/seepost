#include "clientconnection.ih"

SEEPost::ClientConnection::ClientConnection(string const &hostname, size_t port, ClientConfig *conf)
:
connection(),
d_hostname(hostname),
d_conn(getMX(d_hostname), port)
{
	d_conf = conf;
}
