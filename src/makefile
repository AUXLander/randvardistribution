ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

LIB_NAME = libdistribution.so
LIB_SUBDIR = /
LIB_PATH = $(ROOT_DIR)$(LIB_SUBDIR)$(LIB_NAME)

LIB_INSTALL_PATH = /usr/lib/
LIB_INSTALL_PATH64 = /usr/lib64/

CC  = $(CROSS_COMPILE)gcc
CXX = $(CROSS_COMPILE)g++-8
VER = -DVER=$(version)

CFLAGS =-O3
CPPFLAGS =-O3 -std=gnu++2a

OBJ	= libdistribution.o libuser.o
LIB = libdistribution.so

PRG = libuser #libdistribution runtime 
BINS = $(OBJ) $(LIB) $(PRG) 

all: clean $(BINS) install

install:
	if [ -d "$(LIB_INSTALL_PATH)" ]; 	then sudo cp $(LIB_PATH) $(LIB_INSTALL_PATH); 	fi
	if [ -d "$(LIB_INSTALL_PATH64)" ]; 	then sudo cp $(LIB_PATH) $(LIB_INSTALL_PATH64); fi

libdistribution.o: libdistribution.cpp
	$(CXX) $(CPPFLAGS) -fPIC -c libdistribution.cpp

libdistribution.so: libdistribution.o
	$(CXX) $(CPPFLAGS) -fPIC -shared -o $@ $^

libdistribution: libdistribution.o
	$(CXX) $(CPPFLAGS) -o $@ $^

runtime: libdistribution.cpp
	$(CXX) $(CPPFLAGS) -o $@ $^ -L. -ldistribution

libuser.o: libuser.c
	$(CC) $(CFLAGS) -c libuser.c

libuser: libuser.o
	$(CC) $(CFLAGS) -o libuser libuser.o libdistribution.so

clean:
	rm -f $(OBJ) $(BINS)
