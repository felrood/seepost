#include "clientfs.ih"

size_t ClientFS::spaceUsed() {	
	
	size_t space = 0;
	
	vector<size_t> inodes = d_proto->list();
	
	for(size_t idx = 0; idx != inodes.size(); ++idx)
		space += (d_proto->getBlob(inodes[idx])).length();
	
	return space;
}
