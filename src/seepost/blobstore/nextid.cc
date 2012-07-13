#include "blobstore.ih"

size_t SEEPost::BlobStore::nextId() {
	
	string pattern(d_dir + "*.bin");

    glob_t pglob;
    
    glob(pattern.c_str(), 0, NULL, &pglob);
    
    size_t max = 0;
    for(size_t i = 0; i < pglob.gl_pathc; i++) {
        size_t num;

        istringstream stream(string(pglob.gl_pathv[i] + d_dir.length()));

        stream >> num;

        if (num > max)
            max = num;
    }

    globfree(&pglob);
	
	return max + 1;
}
