#include "utils.h"
#include <iostream>
#include <sstream>

using namespace std;

size_t hex2uint(string const &s) {
	
	stringstream ss;
	size_t ret;
	
	ss << hex << s;
	ss >> ret;
	
	return ret;
}
