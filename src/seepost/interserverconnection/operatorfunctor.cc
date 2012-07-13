#include "interserverconnection.ih"

void SEEPost::InterServerConnection::operator()() {

	if(!handshake()) {
		Log::instance() << "Connection terminated" << endl;
		delete d_in;
		delete d_out;
		return;
	}

	DHKX(d_otherserver_key, d_conf->encPrivateKey());

	Log::instance() << "Server connected" << endl;

	string cmd;
	while (true) {
		cmd = readmsg();
		
		Log::instance() << "Server: " << cmd << flush;

		if(cmd == "")
			break;

		if(!processCommand(cmd))
			break;
	}
	Log::instance() << "Connection terminated" << endl;
	delete d_in;
	delete d_out;
}
