#include <unistd.h>

void writeUpper(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	write(1, &c, 1);
}

void writeLower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	write(1, &c, 1);
}

char isChar(char c)
{
	return((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}


void write_string(char *str)
{
	int i = 0;
	while(str[i])
	{
		while(!isChar(str[i]))
			write(1, &str[i++], 1);
		writeUpper(str[i++]);
		while(isChar(str[i]))
			writeLower(str[i++]);
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	int i = 1;
	if(argc > 1)
	{
		while(argv[i])
			write_string(argv[i++]);
	}else {
		write(1, "\n", 1);
	}
	return 0;
}
