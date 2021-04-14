

CC = $(CROSS_COMPILE)g++-8
VER = -DVER=$(version)
CPPFLAGS =-O3#-std=gnu++2a 

PRG	= libdistribution 

OBJ	= libdistribution.o libuser.o

BINS = libdistribution libdistribution.so runtime libuser

all: $(BINS)

libdistribution.o: libdistribution.cpp
	$(CC) $(CPPFLAGS) -fPIC -c libdistribution.cpp

libdistribution.so: libdistribution.o
	$(CC) $(CPPFLAGS) -fPIC -shared -o $@ $^

libdistribution: libdistribution.o
	$(CC) $(CPPFLAGS) -o $@ $^

runtime: libdistribution.cpp
	$(CC) $(CPPFLAGS) -o $@ $^ -L. -ldistribution

libuser.o: libuser.c
	gcc -c libuser.c

libuser: libuser.o
	gcc -o libuser libuser.o libdistribution.so

clean:
	rm -f $(OBJ) $(BINS)
