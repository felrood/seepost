#include "command.ih"

bool Command::quit(istringstream &stream, ClientApplication &app) {
	
	app.conn().writemsg("QUIT bye\n");
	cout << app.conn().readmsg() << flush;

	return false;
}
