#include "clientfs.ih"

map<string, string> ClientFS::read(size_t id) {
	
	// get first index
	string blb = getBlob(1);
	map<size_t, size_t> indices = decodeKVIndex(blb);

	for(size_t idx = 0; idx != indices.size(); ++idx) {
		vector<string> lines = split(getBlob(indices[idx]), '\n');
			
		for(size_t idx2 = 0; idx2 != lines.size(); ++idx2) {
			map<string, string> msg = decodeKV(lines[idx2]);
				
			if(msg["id"].length() != 0 && str2uint(msg["id"]) == id) {
				msg["body"] = getBlob(str2uint(msg["body"]));
				return msg;
			}
		}
	}

	throw FBB::Errno(0, "Message not found!!");
}
