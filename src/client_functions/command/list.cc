#include "command.ih"

bool Command::list(istringstream &stream, ClientApplication &app) {
	size_t num = 0;
	if(!stream.eof()) {
		stream >> num;
		if(!stream.eof()) {
			cout << "List: invalid argument\n";
			return true;
		}
	}

	if(num == 0)
		num = 10;
	
	vector<string> msgs=app.fs().list(num);
	
	map<size_t, map<string, string>> messages;
	
	for(auto it = msgs.begin(); it != msgs.end(); ++it) {
		map<string, string> m = decodeKV(*it);
		
		messages[str2uint(m["id"])] = decodeKV(*it);
	}

	cout << setw(2) << "#" << setw(4) << "ST "
	     << setw(50) << left << "From"
	     << setw(44) << "Subject"
	     << setw(20) << "Time" << endl;
	
	size_t cnt=0;
	
	for(auto it = messages.rbegin(); it != messages.rend(); ++it) {
		map<string, string> msg = (*it).second;
		
		string from = msg["name"] + " <" + msg["from"] + '>';
		
		cout << right << setw(2) << msg["id"] << setw(4) << (msg["status"] + ' ')
		     << setw(50) << left << from.substr(0, 49)
		     << setw(44) << msg["subject"].substr(0, 43)
		     << setw(20) << msg["timestamp"] << endl;
		
		if(++cnt == num) break;
	}
	
	cout << '\n' << cnt << " from " << msgs.size() << " messages listed" << endl;
	
	return true;
}
