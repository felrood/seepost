#include "clientproto.ih"

Public_Key *ClientProto::encpubkey(string const &address) {
	
	string msg = "ENCPUBKEY ";
	msg += address + '\n';
	
	d_conn->writemsg(msg);
	
	string response = d_conn->readmsg();
	
	string head = response.substr(0, response.find('\n'));
	string body = response.substr(response.find('\n')+1);
	
	if(head != "OK") {
		string err = "Command ENCPUBKEY failed: ";
		err += head;
		throw FBB::Errno(0, err.c_str());
	}

	Public_Key *pubkey;	
	try {
		DataSource_Memory cert_dsm(body);
		pubkey = X509::load_key(cert_dsm);
	} catch (Decoding_Error e) {
		string err = "Command ENCPUBKEY failed: ";
		err += e.what();
		throw FBB::Errno(0, err.c_str());
	}
	return pubkey;
}
