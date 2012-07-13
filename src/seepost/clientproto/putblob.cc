#include "clientproto.ih"

void ClientProto::putBlob(size_t id, string blb) {
	
	ostringstream ostr;
	
	ostr << "PUT 0" << hex << id << " {" << blb << "}\n";
	
	d_conn->writemsg(ostr.str());
	
	string response = d_conn->readmsg();
	
	if(response.substr(0, 2) != "OK") {
		throw FBB::Errno(0, response.c_str());
	}
}
