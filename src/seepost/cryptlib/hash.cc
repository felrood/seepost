#include "cryptlib.ih"

string CryptLib::hash(string const &hash, string const &input) {
	Pipe pipe(new Hash_Filter(hash));
	pipe.process_msg(input);
	return pipe.read_all_as_string(0);
}
