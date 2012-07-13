#include "server.ih"

Args parseArgv(int argc, char *argv[]) {

    Args args;

    args.verbose = false;
    args.local = false;

	for(int i = 1; i < argc; i++) {
		string s(argv[i]);

		if(s == "-h") {
			usage();
		}
		if(s == "-v") {
			args.verbose = true;
			continue;
		}
        if(s == "-l") {
            args.local = true;
            continue;
        }
		if(s == "-f" && i + 1 < argc) {
			args.config_dir = string(argv[i+1]);
			i++;
			continue;
		}
		usage();
	}

    return args;
}  
