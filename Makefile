.SILENT:
default: all

all:
	g++ -Wall -Wextra -std=c++11 -Iinclude $(shell find . -name "*.cpp" -not -path "./support/*" -not -name "*test.cpp") -o dist/rts_game_cpp

start: all
	dist/rts_game_cpp

clear:
	clear

test:
	g++ -Wall -Wextra -std=c++11 -Iinclude $(shell find . -name "*.cpp" -not -name "main.cpp") -o dist/rts_game_test
	dist/rts_game_test

check:
	cppcheck -Iinclude --std=c++11 -q --enable=all .

watch:
	clear
	make test
	find *.cpp *.h | entr make clear test check
