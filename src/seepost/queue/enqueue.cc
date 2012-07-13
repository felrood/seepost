#include "queue.ih"

bool SEEPost::Queue::enqueue(Blob &b) {

	size_t num = max() + 1;

	ostringstream path;
	path << d_path << num << ".bin";

    ofstream file(path.str().c_str());

    if (!file.good()) {
        return false;
    }

    for(size_t i = 0; i < b.length(); i++) {
        file << b.data()[i];
    }

	return true;
}