// Returns floor of square root of x 
#include "../libft.h"

int ft_flrsqrt(int x)
{ 
    int i;
	int result;

	i = 1;
	result = 0;
    if (x == 0 || x == 1) 
		return (x);
    while (result <= x) 
    { 
      i++; 
      result = i * i; 
    } 
    return (i - 1); 
}
