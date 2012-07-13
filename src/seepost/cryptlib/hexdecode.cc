#include "cryptlib.ih"

string CryptLib::hexDecode(string const &input) {
	Pipe pipe(new Hex_Decoder);
	pipe.process_msg(input);
	return pipe.read_all_as_string(0);
}
