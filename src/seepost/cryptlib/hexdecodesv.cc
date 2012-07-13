#include "cryptlib.ih"

SecureVector<byte> CryptLib::hexDecodeSV(string const &input) {
	Pipe pipe(new Hex_Decoder);
	pipe.process_msg(input);
	return pipe.read_all(0);
}
