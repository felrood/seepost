#include "queue.ih"

SEEPost::Blob SEEPost::Queue::peek(size_t id) {
	ostringstream path;

	id += min();

	path << d_path << id << ".bin";
	
	ifstream file(path.str().c_str());

	if(!file.good()) {
		return Blob(0, 0, (byte *)0);
	}
	
	stringstream buffer;
	buffer << file.rdbuf();
	string buf = buffer.str();
	
	size_t len = buf.length();
	
	byte *data = new byte[len];
	
	const char *str = buf.c_str();
	
	for(size_t i = 0; i < len; ++i) {
		data[i] = str[i];
	}
	
	return Blob(id, len, data);
}