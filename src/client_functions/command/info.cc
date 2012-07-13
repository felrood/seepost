#include "command.ih"

bool Command::info(istringstream &stream, ClientApplication &app) {

	cout << "Name:         " << app.config().name() << '\n'
		 << "Address:      " << app.config().address() << '\n'
		 << "Enc. key sig: " << pubkeySig(*(app.config().encPublicKey())) << '\n'
		 << "Sign key sig: " << pubkeySig(*(app.config().signPublicKey())) << '\n'
		 << "Server:       " << app.config().server() << ':' << app.config().port() << '\n'
		 << "Server sig:   " << pubkeySig(*(app.config().serverPublicKey())) << '\n'
		 << "Messages:     " << app.fs().list(0).size() << '\n'
		 << "Queue Length: " << app.proto().length() << "\n\n"
		 << "FS version:   " << ClientFS::FS_VERSION << '\n'
		 << "Key:          " << app.fs().hexKey() << '\n'
		 << "IV:           " << app.fs().hexIV() << '\n'
		 << "Inodes:       " << app.proto().list().size() << '\n'
		 << "Space used:   " << app.fs().spaceUsed() << " bytes\n";

	return true;
}
