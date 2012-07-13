#include "command.ih"

bool Command::retr(istringstream &stream, ClientApplication &app) {
	
	app.retr();

	return true;
}
