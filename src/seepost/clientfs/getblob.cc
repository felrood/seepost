#include "clientfs.ih"

string ClientFS::getBlob(size_t id) {
	
	string blb = d_proto->getBlob(id);
	
	Pipe p(get_cipher("AES-256/CBC/PKCS7", d_fs_key, d_fs_iv, DECRYPTION));
	p.prepend(new Hex_Decoder);
	
	p.process_msg(blb);
	
	return p.read_all_as_string(Pipe::LAST_MESSAGE);
}
