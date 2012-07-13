#include "blobstore.ih"

bool SEEPost::BlobStore::del(size_t id) {
	if(!exists(id)) {
		return false;
	}

	ostringstream path;
	path << d_dir << id << ".bin";

	return remove(path.str().c_str()) == 0;
}
