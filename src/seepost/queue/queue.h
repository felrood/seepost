#ifndef SEEPOST_QUEUE_H
#define SEEPOST_QUEUE_H

#include <string>
#include <blob/blob.h>

namespace SEEPost {
	class Queue {
		bool d_good;
		std::string d_path;

		public:
			Queue();
			Queue(std::string path);
			bool good();
			Blob peek();
			Blob peek(size_t id);
			bool drop(size_t id);
			bool enqueue(Blob &b);
			size_t length();
		private:
			size_t min();
			size_t max();
	};
}

#endif