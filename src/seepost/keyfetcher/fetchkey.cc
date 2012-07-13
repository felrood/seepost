#include "keyfetcher.ih"

bool SEEPost::KeyFetcher::fetchKey(string &server) {
	
	int fd;
	try {
		FBB::ClientSocket conn(server, 9012);
		fd = conn.connect();
	} catch (FBB::Errno const &e) {
		cout << "I SEE ERROR FOR " << server << endl;
		cout << "Error: " << e.what() << endl;
		return false;
	}
	FBB::IFdStream in(fd, 1024*1024);
	FBB::OFdStream out(fd, 1024*1024);

	// Send header
	out << "SEEPOST RESOLVER " << PROTOCOL_VERSION << endl;

	string response;

	// Get response
	getline(in, response);

	if(response != "OK") {
		Log::instance() << "Error from resolver: " << response;
		return false;
	}

	// Send query for key
	out << "GET " << server << endl;

	// Response to the query
	getline(in, response);

	if(response != "FOUND") {
		cout << "Response from keyserver: " << response << endl;
		out << "QUIT bye" << endl;
		return false;
	}


	int prev = 0;

	ostringstream cert;
	while(true) {
		int a = in.get();
		if(a == -1) break;
		cert << (char)a;

		if(a == '\n' && prev == '\n') break;
		prev = a;
	}

	out << "QUIT bye" << endl;

	try {
		Botan::DataSource_Memory cert_dsm(cert.str());
		d_pubkey = Botan::X509::load_key(cert_dsm);
	} catch (Botan::Decoding_Error e) {
		cerr << e.what() << endl;
		return false;
	}

	return true;
}
