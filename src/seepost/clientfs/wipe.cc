#include "clientfs.ih"

void ClientFS::wipe() {
	
	vector<size_t> inodes = d_proto->list();
	
	for(size_t idx = 0; idx != inodes.size(); ++idx)
		d_proto->del(inodes[idx]);
	
	initfs();
}
