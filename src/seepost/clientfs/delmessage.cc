#include "clientfs.ih"

bool ClientFS::delMessage(size_t msg_id) {

	map<size_t, size_t> indices = decodeKVIndex(getBlob(1));
	
	for(size_t idx = 0; idx != indices.size(); ++idx) {
		vector<string> headers = split(getBlob(indices[idx]), '\n');
		
		for(auto it = headers.begin(); it != headers.end(); ++it) {
			map<string, string> msg = decodeKV(*it);
			
			if(msg["id"].length() > 0 && str2uint(msg["id"]) == msg_id) {
				
				headers.erase(it);
				
				if(msg["body"].length() > 0) {
					size_t bodyid = str2uint(msg["body"]);
					
					if(bodyid > 3)
						d_proto->del(bodyid);
				}
				
				putBlob(indices[idx], implode(headers, '\n'));
				
				return true;
			}
		}
	}
	
	return false;
}
