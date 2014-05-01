#include <stdio.h>
#include "malloc.h"

int main(int argc, char *argv[]) {
		unsigned int i=5;
		unsigned int j;
		chunk c,c2;
		unsigned char *ptr=heap;
		/* Q1 */
		printf("i: %d\n",get_int(&i));
		set_int(&j, i);
		printf("j: %d\n",get_int(&j));
		/* Q2 */
		c.free=0;
		c.size=5;
		c.addr=0;
		c.next_chunk=0;
		c.previous_chunk=0;
		set_chunk(&c, ptr);
		get_chunk(&c2,ptr);
        return 0;
}
