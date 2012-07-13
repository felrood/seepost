#include "clientconnection.ih"
#include <sstream>

bool SEEPost::ClientConnection::handshake()
{
	ostringstream out;
	out << "SEEPOST " << PROTOCOL_VERSION << " HELLO " << d_hostname << " AUTH " << d_conf->address() << endl;
	
	writemsg(out.str());
	
	string response = readmsg();
	
	if(response != "OK") {
		throw FBB::Errno(0, response.c_str());
	}
	
	return false;
}
