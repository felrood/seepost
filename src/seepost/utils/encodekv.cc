#include "utils.h"
#include <bobcat/errno>

using namespace std;

std::string encodeKV(std::map<std::string, std::string> const &mp) {

	string ret;

	if(mp.size() == 0)
		return ret;

	auto it = mp.begin();
	ret += (*it).first + '=' + (*it).second;
	++it;

	for(; it != mp.end(); ++it) {
		ret += ';' + (*it).first + '=' + (*it).second;
	}

	return ret;
}