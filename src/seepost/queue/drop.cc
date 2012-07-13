#include "queue.ih"

bool SEEPost::Queue::drop(size_t id) {
	if(id != 0) {
		return false;
	}

	ostringstream path;
	id += min();
	path << d_path << id << ".bin";

	return remove(path.str().c_str()) == 0;
}