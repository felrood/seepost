#include "interserverclient.ih"

SEEPost::InterServerClient::InterServerClient(std::string const &server, size_t port, std::string &servername, Botan::Public_Key *pubkey, Botan::Private_Key *privkey)
:
d_hostname(server),
d_servername(servername),
d_port(port)
{
	d_public_key = pubkey;
	d_private_key =  privkey;
}
