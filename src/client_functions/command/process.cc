#include "command.ih"

bool Command::process(string line) {

	string name;
	istringstream stream(line);
	stream >> name;

	try {
		for(size_t idx = 0; idx < d_size; ++idx)
			if(d_commands[idx].name == name)
				return (*d_commands[idx].fun_ptr)(stream, d_app);

	} catch(FBB::Errno const &e) {
		cout << "Error while executing command: " << e.what() << endl;
		return true;
	}
	cout << "Invalid command\n";
	return true;
}
