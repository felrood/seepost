#include "queue.ih"

size_t SEEPost::Queue::length() {
	
	string pattern(d_path + "*.bin");

    glob_t pglob;
    glob(pattern.c_str(), 0, NULL, &pglob);
    size_t ret = pglob.gl_pathc;
    globfree(&pglob);

	return ret;
}