#include "serverconnection.ih"

bool SEEPost::ServerConnection::processCommand(string &cmd) {
	istringstream in(cmd);
	ostringstream out;

	Server::Parser p(in, out, *this);

	p.parse();

	string outstr=out.str();

	return out.str() != "quit";
}
