# This type of builds are used only w/ code unrelated to the hardware we are currently using
#
#

INC_DIR=inc/
SRC_DIR=src/

CPPFLAGS=-Wextra -g
CPP=g++

OBJ=main.o

EXE=a.out

main.o: src/main.cpp src/encryption.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

# %.o: src/%.cpp
#	$(CPP) $(CPPFLAGS) -c $< -o $@

a.out: %.o 
	$(CPP) $(CPPFLAGS) $< $(OBJ) -o $@

all: $(EXE) 
	
clean:
	[ -f "*.o" ] && rm *.o
	[ -f "*.out" ] && rm .out

PHONY: clean all
