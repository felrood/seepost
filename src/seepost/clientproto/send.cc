#include "clientproto.ih"

void ClientProto::send(string const &address, string const &msg) {
	ostringstream ostr;
	
	ostr << "SEND (" << address << ";{" << msg << "})\n";
	
	d_conn->writemsg(ostr.str());
	
	string response = d_conn->readmsg();
	
	if(response.substr(0, 2) != "OK") {
		throw FBB::Errno(0, response.c_str());
	}
}
