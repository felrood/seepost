#include "blob.ih"

ostream &operator<<(ostream &stream, SEEPost::Blob const &b) {
	
	const byte *data = b.data();
	
    stream << hex;

	for(size_t idx = 0; idx != b.length(); ++idx) {
		if(idx % 16 == 0 && idx > 0)
			stream << '\n';
			
		stream << setw(2) << setfill('0') << (int)data[idx] << ' ';
	}

    stream << dec;

	return stream;
}
