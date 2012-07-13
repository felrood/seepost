#include "utils.h"

#include <bobcat/errno>
#include <sys/types.h>
#include <regex.h>
#include <stdio.h>

using namespace std;

bool match_regex(string const &pattern, string const &data) {
	regex_t regex;
	int reti;
	char msgbuf[100];
	bool ret = false;

	/* Compile regular expression */
	reti = regcomp(&regex, pattern.c_str(), 0);
	if(reti){
		regerror(reti, &regex, msgbuf, sizeof(msgbuf));
		regfree(&regex);
		string err("Could not compile regex: ");
		err += msgbuf;
		throw FBB::Errno(0, err.c_str());
	}

	/* Execute regular expression */
	reti = regexec(&regex, data.c_str(), 0, NULL, 0);

	if(!reti) {
		ret = true;
	} else if(reti == REG_NOMATCH) {
		ret = false;
	} else {
		regerror(reti, &regex, msgbuf, sizeof(msgbuf));
		regfree(&regex);

		string err("Regex match failed: ");
		err += msgbuf;
		throw FBB::Errno(0, err.c_str());
	}

	regfree(&regex);

	return ret;
}