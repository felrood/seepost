#include "keyserverconnection.ih"

bool SEEPost::KeyServerConnection::processCommand(string &incmd) {
	istringstream in(incmd);
	
	string cmd;

	in >> cmd;

	if(cmd == "QUIT") {
		writemsg("QUIT bye\n");
		return false;
	} else if(cmd == "GET") {
		string server = incmd.substr(4);
		get(server);
	} else {
		writemsg("ERROR D-101 Command unknown\n");
	}
	return true;
}
