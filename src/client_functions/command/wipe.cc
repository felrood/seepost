#include "command.ih"

bool Command::wipe(istringstream &stream, ClientApplication &app) {
	app.fs().wipe();
	return true;
}
