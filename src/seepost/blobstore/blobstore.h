#ifndef SEEPOST_BLOBSTORE_H
#define SEEPOST_BLOBSTORE_H
#include <string>
#include <vector>
#include <iostream>

#include <blob/blob.h>

namespace SEEPost {
	class BlobStore {
		
		bool d_good;
		std::string d_dir;
		
		public:
			BlobStore(std::string const &dir);
			bool exists(size_t blob_id);
			Blob *get(size_t blob_id);
			bool put(Blob &b);
			size_t nextId();
			bool del(size_t blob_id);
			std::vector<size_t> list();
			
            // getters
			bool good() {
				return d_good;
			}
			
			std::string dir() const {
				return d_dir;
			}
	};
}

#endif
