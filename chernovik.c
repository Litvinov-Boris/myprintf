#include <stdio.h>
#include <stdint.h>
#include "ft_printf.h"

int main(void)
{
	d.d = 125683.152655;
	long_value *a=whole(dexp());
	long_value *b = fraction(dexp(), 1);
	for (int i =0; i<a->size; i++)
		printf("%i ", a->value[i]);
	printf("\n");
	for (int i =0; i<b->size; i++)
		printf("%i ", b->value[i]);
	return(0);
}