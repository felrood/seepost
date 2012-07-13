#ifndef SEEPOST_BLOB_H
#define SEEPOST_BLOB_H
#include <string>
#include <vector>
#include <iostream>

typedef unsigned char byte;

namespace SEEPost {
	class Blob {
		size_t d_id;
		size_t d_length;
		byte *d_data;
		
		public:
			Blob(size_t id, size_t length, byte *data)
				: d_id(id), d_length(length), d_data(data)
			{
				
			}
			~Blob() {
				delete[] d_data;
			}
			
			size_t id() const {
				return d_id;
			}
			
			size_t length() const {
				return d_length;
			}
			
			byte *data() const {
				return d_data;
			}
	};
}

std::ostream &operator<<(std::ostream &stream, const SEEPost::Blob &b);

#endif
