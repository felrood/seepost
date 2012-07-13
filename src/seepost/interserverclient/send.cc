#include "interserverclient.ih"

bool SEEPost::InterServerClient::send(string const &address, string const &msg) {

	ostringstream out;
	out << "SEND (" << address << ";{" << msg << "})\n";
	writemsg(out.str());

	string response=readmsg();

	if(response.substr(0, 2) != "OK") {
		Log::instance() << "Error in delivery: " << response;
	}

	writemsg("QUIT bye\n");

	readmsg();

	return response.substr(0, 2) == "OK";
}