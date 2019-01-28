
all:
	$(CC) -m32 -fPIC -c pagealloc.c
	$(AR) -rsc libpagealloc.a pagealloc.o
	$(CC) -g -m32 test.c libpagealloc.a pagealloc.h -o test

install:
	cp pagealloc.h /usr/local/include/pagealloc.h
	cp libpagealloc.a /usr/local/lib/libpagealloc.a

clean:
	rm -f test *.a *.o
