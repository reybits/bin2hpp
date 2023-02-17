bin2hpp: bin2hpp.o
	g++ -std=c++14 -O2 -o bin2hpp bin2hpp.o

bin2hpp.o: bin2hpp.cpp
	g++ -std=c++14 -O2 -c bin2hpp.cpp

clean:
	rm -f bin2hpp bin2hpp.o

install:
	cp bin2hpp /usr/local/bin/bin2hpp

uninstall:
	rm -f /usr/local/bin/bin2hpp

