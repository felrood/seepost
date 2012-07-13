#include "interserverclient.ih"

bool SEEPost::InterServerClient::encpubkey(string const &address) {

	ostringstream out;
	out << "ENCPUBKEY " << address << '\n';
	writemsg(out.str());

	string response=readmsg();

	if(response.substr(0, 2) != "OK") {
		Log::instance() << "Error in key fetching: " << response;
	}

	d_response = response.substr(response.find_first_of('\n')+1);

	writemsg("QUIT bye\n");

	readmsg();

	return response.substr(0, 2) == "OK";
}
