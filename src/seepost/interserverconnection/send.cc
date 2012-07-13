#include "interserverconnection.ih"

void SEEPost::InterServerConnection::send(string const &address, string const &msg) {

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
	
	writemsg("ERROR C-404 User Does not exist\n");
}