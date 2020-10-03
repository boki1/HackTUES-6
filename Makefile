INC_DIR=inc/
SRC_DIR=src/
TESTS_DIR=tests/

CPPFLAGS=-Wextra -g
CPP=g++

OBJ=main.o
OBJ_TESTS=$(patsubst %.c, %.o, $(wildcard TESTS_DIR/*.c))

EXE_DEBUG=a.out
DEPS=INC_DIR/block.h INC_DIR/internal.h INC_DIR/cryptography.h

all: $(EXE_DEBUG) 

test: 
	(cd $(TESTS_DIR); make tests)
	
clean:
	[ -f "*.o" ] && rm *.o
	[ -f "*.out" ] && rm .out

PHONY: clean all tests
