default: all

all:
	g++ -std=c++11 -Iinclude $(shell find . -name "*.cpp" -not -path "./support/*" -not -name "*test.cpp") -o dist/rts_game_cpp

start: all
	dist/rts_game_cpp

test:
	clear
	g++ -std=c++11 -Iinclude $(shell find . -name "*.cpp" -not -name "main.cpp") -o dist/rts_game_test
	dist/rts_game_test

watch:
	clear
	make test
	find *.cpp *.h | entr make test
