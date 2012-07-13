#include "keyserverconnection.ih"

void SEEPost::KeyServerConnection::operator()() {

	if(!handshake()) {
		Log::instance() << "Connection terminated" << endl;
		delete d_in;
		delete d_out;
		return;
	}

	Log::instance() << "Server connected" << endl;

	string cmd;
	while (true) {
		cmd = readmsg();
		
		Log::instance() << "Server: " << cmd << endl;

		if(cmd == "")
			break;

		if(!processCommand(cmd))
			break;
	}
	
	Log::instance() << "Connection terminated" << endl;
	delete d_in;
	delete d_out;
}
