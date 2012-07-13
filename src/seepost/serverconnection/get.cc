#include "serverconnection.ih"

void SEEPost::ServerConnection::get(size_t idx) {
	Blob *b = d_account->blobstore().get(idx);

	if(b->length() == 0) {
		writemsg("ERROR B-404 Blob not found\n");
		return;
	}
	string response("OK {");

	byte *d = b->data();

	for(size_t i = 0; i != b->length(); ++i) {
		response += (char) d[i];
	}
	response += "}\n";

	writemsg(response.c_str());
}