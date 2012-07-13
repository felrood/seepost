#include "clientfs.ih"

void ClientFS::initfs() {

	// Check for left over inodes
	vector<size_t> lst = d_proto->list();
	
	// Only Inode 0 should exist
	if(lst.size() > 0) {
		throw FBB::Errno(0, "Corrupt FS!");
	}

	// Create Inode 0 with FS version, KEY
	ostringstream out;
	out << "version=1;key=" << genKey(48);
		
	d_proto->putBlob(0, out.str());

	open();

	// Create index inode
	string blb = "0=3";
	putBlob(1, blb);
	
	// Next message id
	putBlob(2, "1");

	// Put in a nice welcome message!		
	DateTime dt;
	string idx = "id=0;status=U;subject=Welcome to SEEPost!;timestamp=";
	idx += dt.rfc2822() + ';';
	idx += "from=admin@" + d_conf->server() + ";name=Admin;body=4";
		
	putBlob(3,  idx);
	putBlob(4, "Dear user,\n\nThank you for using our incredible awesome and secure email like messaging system!\n\nCheers,\nThe Team");
	
	Log::instance() << "New FS created" << nl;
}
