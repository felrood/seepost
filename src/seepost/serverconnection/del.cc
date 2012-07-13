#include "serverconnection.ih"

void SEEPost::ServerConnection::del(size_t idx) {

	if(d_account->blobstore().del(idx)) {
		writemsg("OK\n");
	} else {
		writemsg("ERROR X-666 Undefined error\n");
	}
}