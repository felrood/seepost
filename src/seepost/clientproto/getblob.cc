#include "clientproto.ih"

string ClientProto::getBlob(size_t id) {
	
	ostringstream ostr;
	
	ostr << "GET 0" << hex << id << endl;
	
	d_conn->writemsg(ostr.str());
	
	string response = d_conn->readmsg();
	
	if(response.substr(0, 2) != "OK") {
		throw FBB::Errno(0, response.c_str());
	}
	
	return response.substr(4, response.length()-6);
}
