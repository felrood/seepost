#include "serverconnection.ih"

bool SEEPost::ServerConnection::handshake() {
	string header = readmsg();
	istringstream str(header);
	
	string head;
	int version;
	string hello;
	string servername;
	string auth;
	string address;

	str >> head >> version >> hello >> servername >> auth >> address;
	
	if(head != "SEEPOST" || hello != "HELLO" || auth != "AUTH") {
		writemsg("ERROR A-100 Invalid header\n");
		Log::instance() << "Client send invalid header" << endl;
		return false;
	}
	
	if(version != PROTOCOL_VERSION) {
		ostringstream resp;
		resp << "ERROR A-101 Unsupported protocol version, server only supports version " << PROTOCOL_VERSION << endl;
		writemsg(resp.str());
		Log::instance() << "Client uses protocol version " << version << ", server only supports version " << PROTOCOL_VERSION << endl;
		return false;
	}
	
	if(servername != d_conf->servername()) {
		ostringstream resp;
		resp << "ERROR A-102 Wrong server, domain " << servername << " is not on this server!" << endl;
		writemsg(resp.str());
		Log::instance() << "Client asked for domain " << servername << ", which is not on this server!" << endl;
		return false;
	}

	for(auto it=d_accountstore->accounts().begin(); it!=d_accountstore->accounts().end(); ++it) {
		if((*it)->address() == address) {
			d_account = *it;
		}
	}

	if(!d_account) {
		writemsg("ERROR B-100 Account not known!\n");
		Log::instance() << "Client account not known!" << endl;
		return false;
	}
	
	writemsg("OK\n");
	
	return true;
}
