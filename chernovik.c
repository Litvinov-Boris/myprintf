/*//возведение в степень
int binpow (int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}*/

#include <stdio.h>
#include <stdint.h>
#include "ft_printf.h"
/*union vlint
{
	unsigned int i;
	float d;
}v;*/
int main(void)
{
	d.d = 2458;
	int *a = whole(dexp());
	printf("%i\n\n", dexp());
	while (*a)
	{
		printf("%i\n", *a);
		a++;
	}
	return(0);
}