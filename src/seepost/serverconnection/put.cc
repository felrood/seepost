#include "serverconnection.ih"

void SEEPost::ServerConnection::put(size_t idx, string data) {

	size_t len = data.length();

	byte *d2 = new byte[len];

	for(size_t i = 0; i != len; ++i)
		d2[i] = (byte)data[i];

	Blob b(idx, len, d2);

	if(d_account->blobstore().put(b)) {
		writemsg("OK\n");
	} else {
		writemsg("ERROR X-666 Undefined error\n");
	}
}