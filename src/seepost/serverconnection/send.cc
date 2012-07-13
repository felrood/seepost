#include "serverconnection.ih"

void SEEPost::ServerConnection::send(string const &address, string const &msg) {

	ostringstream ostr;
	DateTime dt;

	ostr << "from_server=" << d_conf->servername() << ";timestamp_server=" << dt.rfc2822() << '\n' << msg;
	string msg2 = ostr.str();

	byte * data = new byte[msg2.length()];

	for(size_t i=0; i<msg2.length(); ++i) {
		data[i] = (byte) msg2[i];
	}

	Blob b(0, msg2.length(), data);

	// local delivery
	for(auto it = d_accountstore->accounts().begin(); it != d_accountstore->accounts().end(); it++ ) {
		if((*it)->address() == address) {
			if ((*it)->inqueue().enqueue(b)) {
				writemsg("OK local delivery\n");
			} else {
				writemsg("ERROR X-666 Undefined error\n");
			}
			return;
		}
	}

	string server = address.substr(address.find_first_of("@")+1);
	server = getMX(server);

	// TODO: dit alles async

	KeyFetcher kf;

	if(!kf.fetchKey(server)) {
		writemsg("ERROR D-100 Cannot fetch key\n");
		return;
	}

	// try to connect to the other server
	InterServerClient isc(server, 9010, d_conf->servername(), &kf.pubkey(), d_conf->encPrivateKey());
	
	if(!isc.connect()) {
		writemsg("ERROR C-100 Cannot connect to server\n");
		return;
	}

	if(isc.send(address, msg)) {
		writemsg("OK external delivery\n");
	} else {
		writemsg("ERROR B-100 Cannot send message\n");
	}
}
