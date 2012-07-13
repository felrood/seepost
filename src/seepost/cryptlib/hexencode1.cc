#include "cryptlib.ih"

string CryptLib::hexEncode(string const &input) {
	Pipe pipe;
	pipe.prepend(new Hex_Encoder);
	pipe.process_msg(input);
	return pipe.read_all_as_string();
}
