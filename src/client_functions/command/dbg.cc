#include "command.ih"

bool Command::dbg(istringstream &stream, ClientApplication &app) {
	size_t num = 0;
	if(!stream.eof()) {
		stream >> num;
		if(!stream.eof()) {
			cout << "Dbg: invalid argument\n";
			return true;
		}
	}

	cout << app.fs().getBlob(num) << endl;
	
	return true;
}
