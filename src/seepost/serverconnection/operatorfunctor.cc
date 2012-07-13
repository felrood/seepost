#include "serverconnection.ih"

void SEEPost::ServerConnection::operator()() {

	if(!handshake()) {
		Log::instance() << "Connection terminated" << endl;
		delete d_in;
		delete d_out;
		return;
	}
	
	DHKX(d_account->encPublicKey(), d_conf->encPrivateKey());

	Log::instance() << "Client connected" << endl;

	string cmd;
	while (true) {
		cmd = readmsg();
		
		Log::instance() << "Client: " << ((cmd.length() > 50) ? (cmd.substr(0, 50) + "...\n") : cmd) << flush;

		if(cmd == "")
			break;

		if(!processCommand(cmd))
			break;
	}
	Log::instance() << "Connection terminated" << endl;
	delete d_in;
	delete d_out;
}
