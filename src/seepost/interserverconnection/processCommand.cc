#include "interserverconnection.ih"

bool SEEPost::InterServerConnection::processCommand(string &incmd) {
	istringstream in(incmd);
	
	string cmd;

	in >> cmd;

	if(cmd == "QUIT") {
		writemsg("QUIT bye\n");
		return false;
	} else if(cmd == "SEND") {

		string sub = incmd.substr(6);

		string address = sub.substr(0, sub.find_first_of(";"));
		string blob = sub.substr(sub.find_first_of(";")+2, sub.length() - address.length() - 5);

		if(address.length() == 0 || blob.length() == 0) {
			writemsg("ERROR C-101 Syntax error\n");
			return true;
		}

		send(address, blob);
	} else if(cmd == "ENCPUBKEY") {
			string address = incmd.substr(10, incmd.length() - 11);
			encpubkey(address);
	} else if(cmd == "SIGNPUBKEY") {
			string address = incmd.substr(11, incmd.length() - 12);
			signpubkey(address);
	} else {
		writemsg("ERROR C-102 command unknown\n");
	}
	return true;
}
