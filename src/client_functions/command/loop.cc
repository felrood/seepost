#include "command.ih"

void Command::loop() {
	while(true) {
		string line;
		cout << "> ";

		getline(cin, line);
				
		if(cin.eof()) {
			cout << '\n';
			return;
		}
		
		if(!process(line))
		break;
	}

}
