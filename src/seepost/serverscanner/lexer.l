%class-name = "Scanner"
%filenames = "scanner"
%namespace = "Server"

word	[a-zA-Z_][a-zA-Z_0-9-]*
decimal	[0-9]+
hex	[0-9a-fA-F]+

%%

[ \t]	/*nothing*/
(.|\n)	return matched()[0];

ERROR		return Server::Parser::ERRORTOKEN;
QUIT		return Server::Parser::QUIT;
SEND		return Server::Parser::SEND;
PEEK		return Server::Parser::PEEK;
DROP		return Server::Parser::DROP;
LENGTH		return Server::Parser::LENGTH;
GET			return Server::Parser::GET;
PUT			return Server::Parser::PUT;
DELETE		return Server::Parser::DELETE;
LIST		return Server::Parser::LIST;
ENCPUBKEY	return Server::Parser::ENCPUBKEY;
SIGNPUBKEY	return Server::Parser::SIGNPUBKEY;

[a-zA-Z_]-{decimal} return Server::Parser::ERRORCODE;

{hex}	return Server::Parser::HEXNUMBER;
{word}	return Server::Parser::WORD;
\{(\\\\|\\\}|[^\}])*\}	return Server::Parser::BLOB;

{word}@[^ \t\n;]+	return Server::Parser::SEEPOST_ADDRESS;

