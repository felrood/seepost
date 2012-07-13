#include "server_functions/server.ih"

void usage() {
	std::cout << "Usage: server [-h] [-v] [-l] [-f config-dir]\n";
	exit(0);
}

int main(int argc, char **argv) {

	Args args = parseArgv(argc, argv);

	Log::initialize(args.verbose ? "&2" : "/dev/null");

	if(args.config_dir == "") {
		args.config_dir = "~/.cppostserver";
	}

	string config_file = args.config_dir + "/config.skf";

	Log::instance() << "Using config file: " << config_file << '\n';

	ServerConfig conf(config_file);
	conf.load();

	if(!conf.good()) {
		if(conf.needsPassword()) {
			string password=readPassword("Password: ");
			conf.setPassword(password);
			conf.load();
		} else {
			cerr << "Config file does not exists or is not readable\n";
			exit(1);
		}
	}

	if(!conf.good()) {
		cerr << "Cannot read config file!\n";
		exit(1);
	}

	AccountStore as(args.config_dir + '/');

	if(!as.good()) {
		cerr << "Cannot read accounts\n";
		exit(1);
	}

	Log::instance() << "Accounts found: " << as.accounts().size() << '\n';

	for (vector<Account*>::iterator i = as.accounts().begin(); i != as.accounts().end(); ++i) { 
		Log::instance() << (*i)->name() << " <" << (*i)->address() << ">\n";
	}
	
	// Start interserver
	InterServer isl(conf.port()-1, &as, &conf);
	thread ist(isl);

	// Start keyserver
	KeyServer ks(conf.port()+1, &conf);
	thread kst(ks);

	// Start client server in main thread
	ServerSocket conn(conf.port());
	conn.listen();
	
	vector<thread*> vt;
	vector<SocketBase*> vsb;
	vector<ServerConnection*> vsc;

	while(true) {
		SocketBase *sb = new SocketBase(conn.accept());
		vsb.push_back(sb);

		ServerConnection *sc = new ServerConnection(sb, &as, &conf);
		vsc.push_back(sc);

		thread *t = new thread(*sc);
		vt.push_back(t);
	}
	
}
