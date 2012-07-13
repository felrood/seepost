#include "keyserver.ih"

void SEEPost::KeyServer::operator()() {

	ServerSocket conn(d_port);
	conn.listen();
	
	vector<thread*> vt;
	vector<SocketBase*> vsb;
	vector<KeyServerConnection*> vsc;

	while(true) {
		SocketBase *sb = new SocketBase(conn.accept());
		vsb.push_back(sb);

		KeyServerConnection *sc = new KeyServerConnection(sb, d_conf);
		vsc.push_back(sc);

		thread *t = new thread(*sc);
		vt.push_back(t);
	}

}