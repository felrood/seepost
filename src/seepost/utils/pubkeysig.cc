#include "utils.h"

using namespace std;
using namespace Botan;

string pubkeySig(Public_Key &pk) {
	Pipe p(new Hash_Filter("SHA-256"), new Hex_Encoder);
	p.process_msg(pk.x509_subject_public_key());
	return p.read_all_as_string();
}