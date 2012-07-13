#include "cryptlib.ih"

string CryptLib::hexEncode(SecureVector<byte> const &input) {
	Pipe pipe(new Hex_Encoder);
	pipe.process_msg(input);
	return pipe.read_all_as_string();
}
