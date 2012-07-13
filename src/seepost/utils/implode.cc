#include "utils.h"
#include <bobcat/errno>

using namespace std;

string implode(vector<string> const &data, char delim) {

	ostringstream ret;

	if(data.size() == 0)
		return ret.str();

	auto it = data.begin();
	ret << (*it);
	++it;

	for(; it != data.end(); ++it) {
		ret << '\n' << (*it);
	}

	return ret.str();
}
