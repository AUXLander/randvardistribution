CC  = $(CROSS_COMPILE)gcc
CXX = $(CROSS_COMPILE)g++-8
VER = -DVER=$(version)

CFLAGS =-O3
CPPFLAGS =-O3 -std=gnu++2a

OBJ	= libdistribution.o libuser.o
LIB = libdistribution.so

PRG = libdistribution runtime libuser
BINS = $(OBJ) $(LIB) #$(PRG) 

all: $(BINS)

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
