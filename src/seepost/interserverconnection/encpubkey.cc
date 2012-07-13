#include "interserverconnection.ih"

void SEEPost::InterServerConnection::encpubkey(string const &address) {
	
	for(auto it = d_accountstore->accounts().begin(); it != d_accountstore->accounts().end(); it++ ) {
		if((*it)->address() == address) {
			string ret = "OK\n";
			ret+= Botan::X509::PEM_encode(*(*it)->encPublicKey());
			writemsg(ret);
			return;
		}
	}
	
	writemsg("ERROR C-404 Key not found\n");
}
