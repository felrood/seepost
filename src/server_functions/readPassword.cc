#include "server.ih"

/*
 * Read a password from stdin without ecohing it
 */

string readPassword(string const &question) {
    cout << question;
    
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    string s;
    getline(cin, s);
    newt.c_lflag &= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    
    cout << '\n';
    
    return s;
}
