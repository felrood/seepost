#include "command.ih"

Command::Command(ClientApplication &app)

: 	d_commands({
		{"help", &Command::help},		// help
		{"quit", &Command::quit},		// quit
		{"q", &Command::quit},			// alias of quit
		{"list", &Command::list},		// list messages in inbox
		{"info", &Command::info},		// display info about inbox, connection, etc
		{"write", &Command::write},		// write mail
		{"read", &Command::read},		// read mail
		{"cmd", &Command::cmd},			// raw command
		{"retr", &Command::retr},		// retrieve messages from queue
		{"wipe", &Command::wipe},		// wipe filesystem and reinit
		{"dbg", &Command::dbg},			// debug command
		{"delete", &Command::del}		// delete message
	}), 
	d_size(12),
	d_app(app)
{

}
