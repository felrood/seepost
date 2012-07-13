#include "clientconnection.ih"

int SEEPost::ClientConnection::connect()
{
	int fd = d_conn.connect();
	d_in = new IFdStream(fd, 1024*1024);
	d_out = new OFdStream(fd, 1024*1024);
	
	handshake();

	try {
		DHKX(d_conf->serverPublicKey(), d_conf->encPrivateKey());
	} catch(Botan::Internal_Error &e) {
		throw FBB::Errno(0, "cannot establish connection.");
	}
	
	return 0;
}
