#include "clientfs.ih"

string ClientFS::hexKey() {
	return hexEncode(d_fs_key.bits_of());
}
