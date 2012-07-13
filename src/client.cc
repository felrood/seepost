#include "client_functions/client.ih"

void usage() {
	std::cout << "Usage: client [-h] [-v] [-f config-file]\n";
	exit(0);
}
   
int main(int argc, char **argv) {

	Args args = parseArgv(argc, argv);
	
	if(args.config_file == "") {
		args.config_file = string(getenv("HOME")) + "/.cppost/config.skf";
	}
	
	Log::initialize(args.verbose ? "&2" : "/dev/null");

	SEEPost::ClientConfig conf(args.config_file);
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
	
    Log::instance() << "Hello " << conf.name() << nl;

    try {
		ClientApplication app(&conf);

		app.init();
		
		Command cmd(app);
		cmd.loop();
		
	} catch(FBB::Errno const &e) {
		cout << "An error occurred: "
		     << e.why() << endl;
	}
    
    Log::instance() << "Bye!" << nl;
}
