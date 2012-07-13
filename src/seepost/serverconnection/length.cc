#include "serverconnection.ih"

void SEEPost::ServerConnection::length() {
	ostringstream response;
	if(!d_account->inqueue().good()) {
		response << "ERROR X-666 Undefined error\n";
	} else {
		response << "OK " << d_account->inqueue().length() << '\n';
	}
	writemsg(response.str());
}