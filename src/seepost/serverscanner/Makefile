%.o: %.cc
	g++ -std=c++0x -Wall -pedantic -c -o $@ $<

lex.cc: scanner.h
scannerbase.h: lexer.l
	flexc++ $< --lex-source=lex.cc --baseclass-header=scannerbase.h

scanner.h: scannerbase.h ../serverparser/parser.h

../%:
	$(MAKE) -C `dirname $@` `basename $@`

depend: make.dep

make.dep: $(wildcard *.cc) $(wildcard *.h)
	g++ -std=c++0x -MM -o $@ $^
