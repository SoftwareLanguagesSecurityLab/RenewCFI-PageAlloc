#ifndef LIB_PAGEALLOC
#define LIB_PAGEALLOC

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct pa_entry_t {
	void* address;
	size_t size;
} pa_entry_t;

#define page_calloc(entry,size) page_alloc(entry,size)

bool page_alloc(pa_entry_t* entry, size_t size);

bool page_realloc(pa_entry_t* entry, size_t size);

void page_free(pa_entry_t* entry);

#endif
