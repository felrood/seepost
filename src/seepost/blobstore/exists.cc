#include "blobstore.ih"

bool SEEPost::BlobStore::exists(size_t id) {
	
	ostringstream path;
	path << d_dir << id << ".bin";
	
	ifstream file(path.str().c_str());
	
	return file.good();
}