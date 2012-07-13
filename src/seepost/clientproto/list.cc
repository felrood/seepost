#include "clientproto.ih"

vector<size_t> ClientProto::list() {
	
	vector<size_t> ret;
	
	d_conn->writemsg("LIST\n");
	
	string response = d_conn->readmsg();
	
	if(response.substr(0, 2) != "OK") {
		throw FBB::Errno(0, "Command LIST failed");
	}
	
	vector<string> inodes = split(response.substr(4, response.length() - 6), ',');
	
	for(size_t idx = 0; idx != inodes.size(); ++idx)
		ret.push_back(hex2uint(inodes[idx]));

	return ret;
}
