#include "serverconnection.ih"

void SEEPost::ServerConnection::peek() {
	Blob b=d_account->inqueue().peek();
	if(b.length() > 0) {
		string response;
		response += "OK {";
		byte *d = b.data();

		for(size_t i = 0; i != b.length(); ++i) {
			response += (char) d[i];
		}
		response += "}\n";
		writemsg(response);
	} else {
		writemsg("ERROR B-404 Blob not found\n");
	}
}