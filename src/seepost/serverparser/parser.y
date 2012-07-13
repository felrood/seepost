%token ERRORTOKEN QUIT SEND PEEK DROP LENGTH GET PUT DELETE LIST ENCPUBKEY SIGNPUBKEY
%token ERRORCODE HEXNUMBER WORD SEEPOST_ADDRESS BLOB

%baseclass-preinclude   value.h

%stype Value

%scanner ../serverscanner/scanner.h
%class-name Parser
%filenames parser

%namespace Server

%%

line:
	errormsg '\n'
|
	quitmsg '\n'
|
	queuemsg '\n'
|
	storagemsg '\n'
|
	sendmsg '\n'
|
	pubkeymsg '\n'
|
	error '\n'
;

errormsg:
	ERRORTOKEN errorcode explanation
	{
		errormsg($2, $3);
	}
;

quitmsg:
	QUIT explanation
	{
		quit($2);
	}
;

queuemsg:
	peekmsg
|
	dropmsg
|
	lengthmsg
;

sendmsg:
	SEND envelope
	{
		send($2);
	}
;

peekmsg:
	PEEK id
	{
		peek($2);
	}
|
	PEEK
	{
		peek();
	}
;

dropmsg:
	DROP id
	{
		drop($2);
	}
;

lengthmsg:
	LENGTH
	{
		length();
	}
;

envelope:
	'(' address ';' blob ')'
	{
		$$ = envelope($2, $4);
	}
;

explanation:
	word explanation
	{
	   	$$ = prepend($2, $1);
	}
|
	word
	{
		$$ = $1;
	}
;

word:
	WORD
	{
		$$ = word();
	}
;

storagemsg:
	GET id
	{
		get($2);
	}
|
	PUT id blob
	{
		put($2, $3);
	}
|
	DELETE id
	{
		del($2);
	}
|
	LIST
	{
		list();
	}
;

pubkeymsg:
	ENCPUBKEY address
	{
		encpubkey($2);
	}
|
	SIGNPUBKEY address
	{
		signpubkey($2);
	}
;

id:
	HEXNUMBER
	{
		$$ = hex();
	}
;

blob:
	BLOB
	{
		$$ = blob();
	}
;

errorcode:
	ERRORCODE
	{
		$$ = string();
	}
;

address:
	SEEPOST_ADDRESS
	{
		$$ = string();
	}
;
