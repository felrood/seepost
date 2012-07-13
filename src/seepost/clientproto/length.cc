#include "clientproto.ih"

size_t ClientProto::length() {
	
	d_conn->writemsg("LENGTH\n");
	string response = d_conn->readmsg();

	if(response.substr(0, 2) != "OK") {
		string err = "Error in LENGTH command: ";
		err += response.c_str();
		throw FBB::Errno(0, err.c_str());
	}

	return str2uint(response.substr(3, response.length() - 3));
}
