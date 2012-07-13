#include "clientfs.ih"

size_t ClientFS::nextMsgID() {

	size_t id = str2uint(getBlob(2));

	ostringstream ostr;
	ostr << (id + 1);

	putBlob(2, ostr.str());

	return id;
}