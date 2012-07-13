#include "keyserverconnection.ih"

void SEEPost::KeyServerConnection::get(string const &servername) {

	if(d_conf->servername() == servername) {
		string cert = Botan::X509::PEM_encode(*d_conf->encPublicKey());
		cert += '\n';

		writemsg("FOUND\n");
		writemsg(cert);
	} else {
		writemsg("NOTFOUND\n");
	}
}