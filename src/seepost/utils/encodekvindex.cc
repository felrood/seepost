#include "utils.h"
#include <bobcat/errno>

using namespace std;

std::string encodeKVIndex(std::map<size_t, size_t> const &mp) {

	ostringstream ret;

	if(mp.size() == 0)
		return ret.str();

	auto it = mp.begin();
	ret << (*it).first << '=' << (*it).second;
	++it;

	for(; it != mp.end(); ++it) {
		ret << '\n' << (*it).first << '=' << (*it).second;
	}

	return ret.str();
}
