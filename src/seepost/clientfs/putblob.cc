#include "clientfs.ih"

void ClientFS::putBlob(size_t id, string blb) {
	
	Pipe p(get_cipher("AES-256/CBC/PKCS7", d_fs_key, d_fs_iv, ENCRYPTION));
	p.append(new Hex_Encoder);
	
	p.process_msg(blb);

	d_proto->putBlob(id, p.read_all_as_string());
}
