#ifndef _COMMAND_H
#define _COMMAND_H
#include <string>
#include <iostream>
#include <clientapplication/clientapplication.h>

class Command {

    struct CMD {
        std::string name;
        bool(*fun_ptr)(std::istringstream &stream, SEEPost::ClientApplication &app);
    };

	CMD d_commands[12];
	size_t d_size;
	SEEPost::ClientApplication d_app;
		
	public:
		Command(SEEPost::ClientApplication &app);
		void loop();
		bool process(std::string line);
		static bool help(std::istringstream &stream, SEEPost::ClientApplication &app);
		static bool quit(std::istringstream &stream, SEEPost::ClientApplication &app);
		static bool list(std::istringstream &stream, SEEPost::ClientApplication &app);
		static bool info(std::istringstream &stream, SEEPost::ClientApplication &app);
		static bool write(std::istringstream &stream, SEEPost::ClientApplication &app);
		static bool read(std::istringstream &stream, SEEPost::ClientApplication &app);
		static bool cmd(std::istringstream &stream, SEEPost::ClientApplication &app);
		static bool retr(std::istringstream &stream, SEEPost::ClientApplication &app);
		static bool wipe(std::istringstream &stream, SEEPost::ClientApplication &app);
		static bool dbg(std::istringstream &stream, SEEPost::ClientApplication &app);
		static bool del(std::istringstream &stream, SEEPost::ClientApplication &app);
};


#endif
