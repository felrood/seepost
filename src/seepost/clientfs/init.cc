#include "clientfs.ih"

void ClientFS::init() {	
	if(!open())
		initfs();
}
