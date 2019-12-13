
all:
	$(CC) -m32 -Wall -Wextra -fPIC -c pagealloc.c
	$(AR) -rsc libpagealloc.a pagealloc.o
	$(CC) -g -m32 -Wall -Wextra test.c libpagealloc.a pagealloc.h -Wl,-wrap=mmap -o test

all64:
	$(CC) -Wall -Wextra -fPIC -c pagealloc.c
	$(AR) -rsc libpagealloc-64.a pagealloc.o
	$(CC) -g -Wall -Wextra test.c libpagealloc-64.a pagealloc.h -Wl,-wrap=mmap -o test

install:
	cp pagealloc.h /usr/local/include/pagealloc.h
	cp libpagealloc.a /usr/local/lib/libpagealloc.a

install64:
	cp pagealloc.h /usr/local/include/pagealloc.h
	cp libpagealloc-64.a /usr/local/lib/libpagealloc-64.a

clean:
	rm -f test *.a *.o
