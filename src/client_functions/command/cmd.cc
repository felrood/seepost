#include "command.ih"

bool Command::cmd(istringstream &stream, ClientApplication &app) {

	string line = stream.str().substr(4);
	line += '\n';

	app.conn().writemsg(line);

	cout << "Response: " << (app.conn().readmsg()) << flush;
	
	return true;
}
