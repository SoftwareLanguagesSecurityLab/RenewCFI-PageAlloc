#include "pagealloc.h"
#include <sys/mman.h>
#include <string.h>

#define PAGE_SIZE 4096

extern void *__real_mmap(void *addr, size_t length, int prot, int flags,
                  int fd, off_t offset);

bool page_alloc(pa_entry_t* entry, size_t size){
	void* address;
	//size += (PAGE_SIZE - (size % PAGE_SIZE));
	address = __real_mmap( 0, size, PROT_READ|PROT_WRITE,
		MAP_PRIVATE|MAP_ANONYMOUS, -1, 0 );
	if( address ){
		entry->address = address;
		entry->size = size;
		return true;
	}else{
		return false;
	} 
}

/* Always allocate a new region and copy over the old contents. */
bool page_realloc(pa_entry_t* entry, size_t size){
	void* address;
	if( size <= entry->size ) return false;
	//size += (PAGE_SIZE - (size % PAGE_SIZE));
	address = __real_mmap( 0, size, PROT_READ|PROT_WRITE,
		MAP_PRIVATE|MAP_ANONYMOUS, -1, 0 );
	if( address ){
		memcpy( address, entry->address, entry->size );
		munmap( entry->address, entry->size );
		entry->address = address;
		entry->size = size;
		return true;
	}else{
		return false;
	}
}

void page_free(pa_entry_t* entry){
	munmap( entry->address, entry->size );
	entry->address = 0;
	entry->size = 0;
}
