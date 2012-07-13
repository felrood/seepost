#include "interserverclient.ih"

bool SEEPost::InterServerClient::connect()
{

	string host = getMX(d_hostname);

	int fd;
	try {
		d_conn = new ClientSocket(host, d_port);
		fd = d_conn->connect();
	} catch (FBB::Errno const &e) {
		cout << "Error: " << e.what() << endl;
		return false;
	}
	
	d_in = new IFdStream(fd, 1024*1024);
	d_out = new OFdStream(fd, 1024*1024);

	handshake();

	DHKX(d_public_key, d_private_key);
	
	return true;
}
