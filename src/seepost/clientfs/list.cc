#include "clientfs.ih"

vector<string> ClientFS::list(size_t num) {
	
	string blb = getBlob(1);
	map<size_t, size_t> indices = decodeKVIndex(blb);

	vector<string> ret;
	for(size_t idx = 0; idx != indices.size(); ++idx)
		split(getBlob(indices[idx]), '\n', ret);

	return ret;
}
