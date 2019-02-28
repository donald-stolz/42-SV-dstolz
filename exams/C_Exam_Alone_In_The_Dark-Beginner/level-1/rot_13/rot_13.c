#include <unistd.h>
void rotate(char c);

void rotate(char c)
{
	if((c > 'm' && c <= 'z') || (c > 'M' && c <= 'Z'))
		c -= 13;	
	else if((c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm'))
		c += 13;
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	int i = 0;

	if(argc == 2)
		while(argv[1][i])
			rotate(argv[1][i++]);
	write(1, "\n", 1);
	return (0);
}
