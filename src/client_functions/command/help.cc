#include "command.ih"

bool Command::help(istringstream &stream, ClientApplication &app) {
    cout << "Available commands:\n"
		 << "\thelp             this message\n"
		 << "\tretr             retrieve new messages\n"
		 << "\tlist [length]    list messages in inbox\n"
		 << "\twrite <address>  write a message\n"
         << "\tread <id>        read a message\n"
         << "\tdelete <id>		remove message\n"
		 << "\tinfo             show info about this system\n"
		 << "\tcmd              execute system command\n"
		 << "\twipe				destroys all and everything. use with caution.\n"
		 << "\tdbg <id>			debug command\n"
		 << "\tquit             quit client\n";
	return true;
}
