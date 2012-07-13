#include "clientproto.ih"

void ClientProto::init() {

	size_t msgs = length();

	if(msgs == 0) {
		cout << "You have no new messages" << endl;
	} else if(msgs == 1) {
		cout << "You have 1 new message" << endl;
	} else {
		cout << "You have " << msgs << " new messages!" << endl;
	}
}
