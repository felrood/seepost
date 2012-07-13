#include "command.ih"

bool Command::read(istringstream &stream, ClientApplication &app) {

	if(stream.eof()) {
		cout << "Read: invalid argument\n";
		return true;
	}

	size_t msg_id = 0;
	stream >> msg_id;

	if(!stream.eof()) {
		cout << "Read: invalid argument\n";
		return true;
	}

	map<string, string> msg = app.fs().read(msg_id);
	
	cout << "From: " << msg["name"] << " <" << msg["from"] << ">\n"
		 << "Signature: " << msg["sign"] << ", verified at " << msg["sign_verified"] << '\n'
	     << "Date: " << msg["timestamp"] << '\n'
	     << "Status: " << msg["status"] << ", Priority: " << msg["prio"] << '\n'
	     << "Subject: " << msg["subject"] << "\n\n"
	     << msg["body"] << endl;

	return true;
}
