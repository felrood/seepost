#include "clientfs.ih"

string ClientFS::hexIV() {
	return hexEncode(d_fs_iv.bits_of());
}
