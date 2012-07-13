#include "command.ih"

bool Command::del(istringstream &stream, ClientApplication &app) {

	if(stream.eof()) {
		cout << "Delete: invalid argument\n";
		return true;
	}

	size_t msg_id = 0;
	stream >> msg_id;

	if(!stream.eof()) {
		cout << "Delete: invalid argument\n";
		return true;
	}

	cout << "Message " << (!app.fs().delMessage(msg_id) ? "could not be" : "") << " deleted" << endl;

	return true;
}
