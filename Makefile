all: clean build

build:
	g++ main.cpp -o frupal -g -Wall -Werror -lncurses

clean:
	rm -f *.o frupal
