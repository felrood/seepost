#include "clientfs.ih"

size_t ClientFS::nextInodeID() {
	vector<size_t> inodes = d_proto->list();
	sort(inodes.begin(), inodes.end());
	return inodes[inodes.size() - 1] + 1;
}
