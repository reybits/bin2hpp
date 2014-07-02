bin2hpp: bin2hpp.o
	g++ -o bin2hpp bin2hpp.o

bin2hpp.o: bin2hpp.cpp
	g++ -c bin2hpp.cpp

clean:
	rm -f bin2hpp bin2hpp.o

install:
	cp rescompiler /usr/local/bin/bin2hpp

uninstall:
	rm -f /usr/local/bin/bin2hpp

