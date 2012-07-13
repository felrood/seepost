#include "client.ih"

Args parseArgv(int argc, char *argv[]) {

    Args args;

    args.verbose = false;

	for(int i = 1; i < argc; i++) {
		string s(argv[i]);

		if(s == "-h") {
			usage();
		}
		if(s == "-v") {
			args.verbose = true;
			continue;
		}
		if(s == "-f" && i + 1 < argc) {
			args.config_file = string(argv[i+1]);
			i++;
			continue;
		}
		usage();
	}

    return args;
}  
