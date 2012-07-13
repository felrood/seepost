#include "serverconfig.ih"

bool SEEPost::ServerConfig::loadValues(CSimpleIniA &ini) {

	ini.SetMultiLine(true);

	d_port = atoi(ini.GetValue("server", "port"));
	d_servername = ini.GetValue("server", "name");

	string sign_priv(ini.GetValue("server", "sign_priv"));
	string enc_priv(ini.GetValue("server", "enc_priv"));
	
	string sign_pub(ini.GetValue("server", "sign_pub"));
	string enc_pub(ini.GetValue("server", "enc_pub"));

	try {
		AutoSeeded_RNG rng;
		DataSource_Memory sign_priv_dsm(sign_priv);
		d_sign_priv = PKCS8::load_key(sign_priv_dsm, rng, "");

		DataSource_Memory enc_priv_dsm(enc_priv);
		d_enc_priv = PKCS8::load_key(enc_priv_dsm, rng , "");

		DataSource_Memory sign_pub_dsm(sign_pub);
		d_sign_pub = X509::load_key(sign_pub_dsm);

		DataSource_Memory enc_pub_dsm(enc_pub);
		d_enc_pub = X509::load_key(enc_pub_dsm);

	} catch (Botan::Decoding_Error e) {
		cerr << e.what() << endl;
		d_good = false;
	}
    
    return d_good;
}
