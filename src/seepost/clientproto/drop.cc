#include "clientproto.ih"

void ClientProto::drop(size_t id) {
	
	ostringstream ostr;
	
	ostr << "DROP 0" << hex << id << '\n';
	
	d_conn->writemsg(ostr.str());

	string response = d_conn->readmsg();

	if(response.substr(0, 2) != "OK") {
		string err = "Error in DROP command: ";
		err += response.c_str();
		throw FBB::Errno(0, err.c_str());
	}
}
