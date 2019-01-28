#include "pagealloc.h"
#include <stdio.h>

int main(int argc, char** argv){
	pa_entry_t pa_buf;
	uint8_t* buf;
	int i;
	if( page_alloc(&pa_buf, 27) ){
		buf = (uint8_t*)pa_buf.address;
		for( i = 0; i < 26; i++ ){
			buf[i] = 'A'+i;
		}
		puts( buf );
		if( page_realloc(&pa_buf, 4096+27) ){
			buf = (uint8_t*)(pa_buf.address + 4096);
			for( i = 0; i < 26; i++ ){
				buf[i] = 'a'+i;
			}
			puts(buf);
			buf = (uint8_t*)(pa_buf.address);
			puts(buf);
			page_free(&pa_buf);		
		}
	}
}
