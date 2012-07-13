#include "blobstore.ih"

SEEPost::Blob *SEEPost::BlobStore::get(size_t id) {
	
	if(!exists(id)) {
		byte *data = new byte[0];
		Blob *b = new Blob(id, 0, data);
		return b;
	}
	
	ostringstream path;
	path << d_dir << id << ".bin";
	
	ifstream file(path.str().c_str());
	
	stringstream buffer;
	buffer << file.rdbuf();
	string buf = buffer.str();
	
	size_t len = buf.length();
	
	byte *data = new byte[len];
	
	const char *str = buf.c_str();
	
	for(size_t i = 0; i < len; ++i) {
		data[i] = str[i];
	}
	
	Blob *b = new Blob(id, len, data);
	return b;
}