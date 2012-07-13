#include "account.ih"

SEEPost::Account::Account(std::string const &filename, std::string const &dir)

: d_good(false), d_name(""), d_address(""), d_sign_pub(0), d_enc_pub(0), d_blobstore("")

 {

    d_good = false;
    ifstream file(filename.c_str());
    if(!file.good()) {
        return;
    }

	stringstream buffer;
	buffer << file.rdbuf();
	string txt = buffer.str();

    CSimpleIniA ini;
    ini.SetMultiLine(true);
    int ret = ini.LoadData(txt);

    if (ret != SI_OK) {
        return;
    }

    if (ini.GetSectionSize("account") <= 0) {
        return;
    }

	d_name = ini.GetValue("account", "name");
	d_address = ini.GetValue("account", "address");

    string sign_pub(ini.GetValue("account", "sign_pub"));
	string enc_pub(ini.GetValue("account", "enc_pub"));

	try {
		Botan::DataSource_Memory sign_pub_dsm(sign_pub);
		d_sign_pub = Botan::X509::load_key(sign_pub_dsm);

		Botan::DataSource_Memory enc_pub_dsm(enc_pub);
		d_enc_pub = Botan::X509::load_key(enc_pub_dsm);

	} catch (Botan::Decoding_Error e) {
		cerr << e.what() << endl;
		return;
	}
	
	d_blobstore = BlobStore(dir + "blobstore/" + d_address + "/");
	
	if(!d_blobstore.good()) {
		return;
	}

	string queuePath = dir + "inqueue/" + d_address + "/";

	d_inqueue = Queue(queuePath);

	if(!d_inqueue.good()) {
		return;
	}

    d_good = true;
}
