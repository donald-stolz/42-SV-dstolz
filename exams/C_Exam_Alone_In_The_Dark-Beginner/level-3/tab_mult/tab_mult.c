#include <unistd.h>

int ft_atoi(char *str)
{
	int res = 0;
	int i = 0;

	while(str[i])
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return res;
}

void put_str(char *str)
{
	int i = 0;
	while(*(str + i))
		write(1, &str[i++], 1);
}

void put_num(int tep)
{
	int num = tep;
	int rev = 0;
	char temp;
	int len = 0;
	while(num > 0)
	{
		rev *= 10;
		rev += num % 10;
		num /= 10;
		len++;
	}
	while(len > 0)
	{
		temp = rev % 10 + '0';
		write(1, &temp, 1);
		rev /= 10;
		len--;
	}
	write(1, "\n", 1);
}

void print_table(char *str)
{
	int arg = ft_atoi(str);
	int res1 = 1 * arg;
	int res2 = 2 * arg;
	int res3 = 3 * arg;
	int res4 = 4 * arg;
	int res5 = 5 * arg;
	int res6 = 6 * arg;
	int res7 = 7 * arg;
	int res8 = 8 * arg;
	int res9 = 9 * arg;

	write(1, "1 x ", 4);
	put_str(str);
	write(1, " = ", 3);
	put_num(res1);

	write(1, "2 x ", 4);
    put_str(str);
    write(1, " = ", 3);
    put_num(res2);

	write(1, "3 x ", 4);
    put_str(str);
    write(1, " = ", 3);
    put_num(res3);
    
	write(1, "4 x ", 4);
    put_str(str);
    write(1, " = ", 3);
    put_num(res4);

	write(1, "5 x ", 4);
    put_str(str);
    write(1, " = ", 3);
    put_num(res5);
   
	write(1, "6 x ", 4);
    put_str(str);
    write(1, " = ", 3);
    put_num(res6);
   
	write(1, "7 x ", 4);
    put_str(str);
    write(1, " = ", 3);
    put_num(res7);
 
	write(1, "8 x ", 4);
    put_str(str);
    write(1, " = ", 3);
    put_num(res8);

	write(1, "9 x ", 4);
    put_str(str);
    write(1, " = ", 3);
    put_num(res9);
}

int main(int argc, char **argv)
{
	if(argc == 2)
		print_table(argv[1]);
	else
		write(1, "\n", 1);	
	return 0;
}

