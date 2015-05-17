CXX=g++
CPPFLAGS=-Wall -Wextra -std=c++11 -Iinclude
LDFLAGS=
LDLIBS=

TEST_SRCS=$(shell find . -name "*.cpp" -not -name "main.cpp")
TEST_OBJS=$(subst .cpp,.o,$(TEST_SRCS))

MAIN_SRCS=$(shell find . -name "*.cpp" -not -path "./support/*" -not -name "*test.cpp" -not -name "*support.cpp")
MAIN_OBJS=$(subst .cpp,.o,$(MAIN_SRCS))

all: test main

main: $(MAIN_OBJS)
	$(CXX) $(LDFLAGS) -o main $(MAIN_OBJS) $(LDLIBS)

test: $(TEST_OBJS)
	$(CXX) $(LDFLAGS) -o test $(TEST_OBJS) $(LDLIBS)

depend: .depend

.depend: $(MAIN_SRCS) $(TEST_SRCS)
	rm -f .depend
	$(CXX) $(CPPFLAGS) -MM $^>>.depend

clean:
	rm -f $(TEST_OBJS) $(MAIN_OBJS)

dist-clean: clean
	$(RM) .depend

include .depend