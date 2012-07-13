#include "serverconnection.ih"

void SEEPost::ServerConnection::signpubkey(string const &address) {

	for(auto it = d_accountstore->accounts().begin(); it != d_accountstore->accounts().end(); ++it) {
		if((*it)->address() == address) {
			
			string ret = "OK\n";
			ret+= Botan::X509::PEM_encode(*(*it)->signPublicKey());
			writemsg(ret);
			return;
		}
	}

	string server = address.substr(address.find_first_of("@")+1);
	server = getMX(server);
	
	KeyFetcher kf;
	if(!kf.fetchKey(server)) {
		writemsg("ERROR D-100 Cannot fetch key\n");
		return;
	}
	
	InterServerClient isc(server, 9010, d_conf->servername(), &kf.pubkey(), d_conf->encPrivateKey());

	if(!isc.connect()) {
		writemsg("ERROR C-100 Cannot connect to server\n");
		return;
	}

	if(isc.signpubkey(address)) {
		string ret = "OK\n";
		ret += isc.response();
		writemsg(ret);
	} else {
		writemsg("ERROR C-101 Cannot fetch key\n");
	}


}
