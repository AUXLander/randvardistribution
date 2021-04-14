

CC = $(CROSS_COMPILE)g++-8
VER = -DVER=$(version)
CPPFLAGS =-O3#-std=gnu++2a 

PRG	= libdistribution 

OBJ	= libdistribution.o

BINS = libdistribution libdistribution.so runtime

all: $(BINS)

#dstrbtn: $(OBJ)

libdistribution.o: libdistribution.cpp
	$(CC) $(CPPFLAGS) -c libdistribution.cpp

libdistribution.so: libdistribution.cpp
	$(CC) $(CPPFLAGS) -fPIC -shared -o $@ libdistribution.cpp -lc

libdistribution: libdistribution.o
	$(CC) $(CPPFLAGS) -o $@ $^

runtime: libdistribution.cpp
	$(CC) $(CPPFLAGS) -o $@ $^ -L. -ldistribution
clean:
	rm -f $(OBJ) $(BINS)
