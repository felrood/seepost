#include "connection.ih"

string SEEPost::connection::readmsg()
{
	if(!d_use_enc) {
		string line;
		getline(*d_in, line);
		return line;
	}

	ostringstream input;
	string ret("\n");
	while(true) {
		for(size_t i = 0; i < 16; ++i) {
			int a = d_in->get();
			if(a == -1) {
				Log::instance() << "Broken connection" << endl;
				return ret;
			}
			
			input << (byte)a;
		}
		if(d_in->rdbuf()->in_avail() == 0) break;
	}

	try {
		d_enc_in->process_msg(input.str());
		ret = d_enc_in->read_all_as_string(Pipe::LAST_MESSAGE);
	} catch (Botan::Decoding_Error &e) {
		ret = "\n";
		Log::instance() << "Decoding error: " << e.what() << endl;
		Log::instance() << "Input len was: " << input.str().length() << endl;
		d_enc_out = new Pipe(get_cipher("AES-256/CBC/PKCS7", *d_key, *d_iv, ENCRYPTION));
		d_enc_in = new Pipe(get_cipher("AES-256/CBC/PKCS7", *d_key, *d_iv, DECRYPTION));
	}
	return ret;
}
