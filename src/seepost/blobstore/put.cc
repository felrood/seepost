#include "blobstore.ih"

bool SEEPost::BlobStore::put(Blob &b) {
	
    ostringstream path;
	path << d_dir << b.id() << ".bin";

    ofstream file(path.str().c_str());

    if (!file.good()) {
        return false;
    }

    for(size_t i = 0; i < b.length(); i++) {
        file << b.data()[i];
    }

	return true;
}
