#include <stdio.h>
#include <stdint.h>
#include "ft_printf.h"

int main(void)
{
	ld.ld = 5.256955;
	long_value *a = lfraction(longdexp(), 1);
	/*for (int i = 0; i < a->size; i++)
	{
		printf("%i ", a->value[i]);
	}*/
	printf("%.20Lf", ld.ld);
	return(0);
}