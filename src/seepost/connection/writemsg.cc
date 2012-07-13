#include "connection.ih"

void SEEPost::connection::writemsg(string const &msg)
{
	if(!d_use_enc) {
		*d_out << msg << flush;
		return;
	}

	d_enc_out->process_msg(msg);

	string foo = d_enc_out->read_all_as_string(Pipe::LAST_MESSAGE);

	*d_out << foo << flush;
}
