#include "interserver.ih"

void SEEPost::InterServer::operator()() {

	ServerSocket conn(d_port);
	conn.listen();
	
	vector<thread*> vt;
	vector<SocketBase*> vsb;
	vector<InterServerConnection*> vsc;

	while(true) {
		SocketBase *sb = new SocketBase(conn.accept());
		vsb.push_back(sb);

		InterServerConnection *sc = new InterServerConnection(sb, d_accountstore, d_conf);
		vsc.push_back(sc);

		thread *t = new thread(*sc);
		vt.push_back(t);
	}

}