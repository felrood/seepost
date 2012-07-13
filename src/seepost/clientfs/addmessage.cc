#include "clientfs.ih"

void ClientFS::addMessage(string const &headers, string const &body) {

	size_t inode = nextInodeID();
	putBlob(inode, body);
	
	size_t msg_id = nextMsgID();
	
	ostringstream h;
	h << "id=" << msg_id << ";body=" << inode << ';' << headers;
	
	map<size_t, size_t> indices = decodeKVIndex(getBlob(1));
	
	size_t last_idx_id = indices[indices.size() - 1];
	vector<string> last_idx = split(getBlob(last_idx_id), '\n');
	
	// Split large indices
	if(last_idx.size() >= 128) {
		size_t new_idx = nextInodeID();
		indices[indices.size()] = new_idx;
		
		putBlob(1, encodeKVIndex(indices));
		putBlob(new_idx, h.str());
	} else {
		last_idx.push_back(h.str());
		putBlob(last_idx_id, implode(last_idx, '\n'));
	}
}
