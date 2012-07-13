#include "queue.ih"

size_t SEEPost::Queue::min() {
	string pattern(d_path + "*.bin");

    glob_t pglob;
    
    glob(pattern.c_str(), 0, NULL, &pglob);
    
    size_t min = 0;
    --min;
    for(size_t i = 0; i < pglob.gl_pathc; i++) {
        size_t num;

        istringstream stream(string(pglob.gl_pathv[i] + d_path.length()));

        stream >> num;

        if (num < min)
            min = num;
    }
    if(pglob.gl_pathc == 0) {
    	min = 0;
    }

    globfree(&pglob);

    return min;
}