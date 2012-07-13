#include "interserverconnection.ih"

bool SEEPost::InterServerConnection::handshake() {
	string header = readmsg();
	istringstream str(header);
	
	string head;
	int version;
	string hello;
	string servername;
	string auth;
	string otherserver;

	str >> head >> version >> hello >> servername >> auth >> otherserver;
	
	if(head != "SEEPOST" || hello != "HELLO" || auth != "AUTH") {
		writemsg("ERROR A-100 Invalid header\n");
		Log::instance() << "Client send invalid header" << endl;
		return false;
	}
	
	if(version != PROTOCOL_VERSION) {
		ostringstream resp;
		resp << "ERROR A-101 Unsupported protocol version, server only supports version " << PROTOCOL_VERSION << '\n';
		writemsg(resp.str());
		Log::instance() << "Other server uses protocol version " << version << ", server only supports version " << PROTOCOL_VERSION << endl;
		return false;
	}
	
	if(servername != d_conf->servername()) {
		ostringstream resp;
		resp << "ERROR A-102 Wrong server, domain " << servername << " is not on this server!\n";
		writemsg(resp.str());
		Log::instance() << "Server asked for domain " << servername << ", which is not on this server!" << endl;
		return false;
	}

	KeyFetcher kf;

	if(!kf.fetchKey(otherserver)) {
		writemsg("ERROR D-100 Cannot fetch key\n");
		Log::instance() << "Cannot fetch key of other server" << endl;
		return false;
	}
	d_otherserver_key = &kf.pubkey();
	
	writemsg("OK\n");
	
	return true;
}
