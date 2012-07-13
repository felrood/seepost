#include "serverconnection.ih"

void SEEPost::ServerConnection::drop(size_t id) {
	if(d_account->inqueue().drop(id)) {
		writemsg("OK\n");
	} else {
		writemsg("ERROR X-666 Undefined error\n");
	}
}