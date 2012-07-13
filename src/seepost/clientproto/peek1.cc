#include "clientproto.ih"

string ClientProto::peek() {
	
	d_conn->writemsg("PEEK\n");
	string response = d_conn->readmsg();

	if(response.substr(0, 2) != "OK") {
		string err = "Error in PEEK command: ";
		err += response.c_str();
		throw FBB::Errno(0, err.c_str());
	}

	return response.substr(4, response.length() - 6);
}
