#include "keyserverconnection.ih"

SEEPost::KeyServerConnection::KeyServerConnection(SocketBase *sb, ServerConfig *conf)
:
connection()
{
	d_conf = conf;
	
	int fd = sb->socket();
	
	d_in = new IFdStream(fd, 1024*1024);
	d_out = new OFdStream(fd, 1024*1024);
}
