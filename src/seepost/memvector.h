#ifndef SEEPOST_MEMVECTOR_H
#define SEEPOST_MEMVECTOR_H
#include <algorithm>
#include <iostream>
#include <botan/secmem.h>

namespace SEEPost {

	template <typename Type>
	std::ostream &operator<<(std::ostream &os, Botan::MemoryVector<Type> const &vec)
	{
		os << vec.size() << ' ';
		for(size_t i = 0; i < vec.size(); ++i) {
			os << vec[i];
		}
		return os;
		//return os.write(reinterpret_cast<char*>(*vec), vec.size() * sizeof(Type));
	}

	template <typename Type>
	std::istream &operator>>(std::istream &is, Botan::MemoryVector<Type> &vec)
	{
		size_t size;
		is >> size;
		if (is.get() != ' ')
			is.setstate(std::ios::failbit);
		else
		{
			//Type buffer[size];
			//is.read(reinterpret_cast<char *>(buffer), size * sizeof(Type));
			//vec.copy(buffer, size);

			for(size_t i=0; i < size; ++i) {
				vec.push_back(is.get());
			}

		}
		return is;
	}

}

#endif
