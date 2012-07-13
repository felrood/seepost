#include "keyserverconnection.ih"

bool SEEPost::KeyServerConnection::handshake() {
	string response = readmsg();
	
	istringstream header(response);
	string seepost, resolver;
	size_t version;

	header >> seepost >> resolver >> version;

	if(seepost != "SEEPOST" || resolver != "RESOLVER" || version != PROTOCOL_VERSION) {
		writemsg("ERROR A-100 Invalid Header");
		Log::instance() << "Invalid header from resolver" << endl;
		return false;
	}
	
	writemsg("OK\n");
	
	return true;
}
