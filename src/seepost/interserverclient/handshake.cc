#include "interserverclient.ih"

bool SEEPost::InterServerClient::handshake() {

	ostringstream head;
	head << "SEEPOST " << PROTOCOL_VERSION << " HELLO " << d_hostname << " AUTH " << d_servername << endl;
	writemsg(head.str());

	string response = readmsg();

	if(response != "OK") {
		Log::instance() << "Error in handshake: " << response << endl;
		return false;
	}

	return true;
}
