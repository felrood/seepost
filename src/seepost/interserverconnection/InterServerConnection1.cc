#include "interserverconnection.ih"

SEEPost::InterServerConnection::InterServerConnection(SocketBase *sb, AccountStore *as, ServerConfig *conf)
:
connection()
{
	d_accountstore = as;
	d_conf = conf;
	
	int fd = sb->socket();
	
	d_in = new IFdStream(fd, 1024*1024*16);
	d_out = new OFdStream(fd, 1024*1024*16);
}
