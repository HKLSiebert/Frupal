all: clean build

build:
	g++ *.cpp -o frupal -g -Wall -Werror -lncurses

clean:
	rm -f *.o frupal
