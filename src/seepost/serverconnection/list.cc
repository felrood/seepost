#include "serverconnection.ih"

void SEEPost::ServerConnection::list() {
	vector<size_t> lst = d_account->blobstore().list();

	ostringstream out;
	out << "OK {";
	for(size_t i=0; i != lst.size(); ++i) {
		out << hex << lst[i];
		if(i < lst.size() -1 )
			out << ',';
	}
	out << "}\n";

	writemsg(out.str().c_str());
}