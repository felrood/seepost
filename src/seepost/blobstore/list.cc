#include "blobstore.ih"

vector<size_t> SEEPost::BlobStore::list() {

	vector<size_t> list;

	string pattern(d_dir + "*.bin");

    glob_t pglob;
    
    glob(pattern.c_str(), 0, NULL, &pglob);
    
    for(size_t i = 0; i < pglob.gl_pathc; i++) {
        size_t num;

        istringstream stream(string(pglob.gl_pathv[i] + d_dir.length()));

        stream >> num;

        list.push_back(num);
    }

    globfree(&pglob);

    return list;
}