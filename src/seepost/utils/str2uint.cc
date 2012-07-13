#include "utils.h"
#include <iostream>
#include <sstream>

using namespace std;

size_t str2uint(string const &s) {
	istringstream istr(s);
	size_t ret;
	
	istr >> ret;
	
	return ret;
}
