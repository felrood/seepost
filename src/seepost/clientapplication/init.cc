#include "clientapplication.ih"

void ClientApplication::init() {
	
	d_conn = new ClientConnection(d_conf->server(), d_conf->port(), d_conf);
	d_conn->connect();
	
	try {
		d_proto = new ClientProto(d_conn);
		d_proto->init();

		d_fs = new ClientFS(d_proto, d_conf);
		d_fs->init();
	} catch (FBB::Errno const &e) {
		cerr << "Error while opening FS: " << e.what() << endl;
	}
}
