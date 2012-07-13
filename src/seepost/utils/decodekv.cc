#include "utils.h"
#include <bobcat/errno>

using namespace std;

map<string, string> decodeKV(string const &s) {
	map<string, string> config;
	
	vector<string> conf = split(s, ';');
	for(auto it = conf.begin(); it != conf.end(); ++it) {
		vector<string> kv = split(*it, '=');
		if(kv.size() != 2) throw FBB::Errno(0, "Invalid FS config");
		
		config.insert(pair<string, string>(kv[0], kv[1]));
	}
	
	return config;
}

void decodeKV(string const &s, map<string, string> &config) {
	vector<string> conf = split(s, ';');
	for(auto it = conf.begin(); it != conf.end(); ++it) {
		vector<string> kv = split(*it, '=');
		if(kv.size() != 2) throw FBB::Errno(0, "Invalid FS config");
		
		config.insert(pair<string, string>(kv[0], kv[1]));
	}
}
map<size_t, size_t> decodeKVIndex(string const &s) {
	map<size_t, size_t> index;
	
	vector<string> idx = split(s, '\n');
	for(auto it = idx.begin(); it != idx.end(); ++it) {
		vector<string> kv = split(*it, '=');
		if(kv.size() != 2) throw FBB::Errno(0, "Invalid FS config");
		
		index.insert(pair<size_t, size_t>(str2uint(kv[0]), str2uint(kv[1])));
	}
	
	return index;
}
