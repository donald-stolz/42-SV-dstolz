unsigned int lcm(unsigned int a, unsigned int b)
{
	int max;
	int hcf = 1;
	int i = 0;

	max = (a > b) ? a : b;
	while (max > i++)
		if (a % i == 0 && b % i == 0)
			hcf = i;
	return ((a*b)/hcf);
}
