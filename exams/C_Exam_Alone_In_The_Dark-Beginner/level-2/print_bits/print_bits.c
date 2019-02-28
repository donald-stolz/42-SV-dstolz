#include <unistd.h>

void print_bits(unsigned char octet)
{
	int i = 256;
	while( i >>= 1)
		(i & octet) ? write(1, "1", 1) : write(1, "0", 1);
}

