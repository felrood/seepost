%.o: %.cc
	g++ -std=c++0x -Wall -pedantic -c -o $@ $<

parse.cc: parser.h
parserbase.h: parser.y
	bisonc++ -V $< --parsefun-source=parse.cc --baseclass-header=parserbase.h

parser.h: parserbase.h ../serverscanner/scanner.h

../%:
	-$(MAKE) -C `dirname $@` `basename $@`

depend: make.dep

make.dep: $(wildcard *.cc) $(wildcard *.h)
	g++ -std=c++0x -MM -o $@ $^
