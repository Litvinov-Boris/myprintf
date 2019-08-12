#include <stdio.h>
#include <stdint.h>
#include "ft_printf.h"

int main(void)
{
	ld.ld = -9.6341541;
	t_format a;
	a.flag = 0;
	a.flag |=0x01;
	//a.flag |=0x02;
	a.flag |=0x04;
	//a.flag |=0x08;
	a.flag |=0x10;
	a.prec = 0;
	a.width = 20;
	char *str = zerostr(a.prec);
	finalprintnahoild(&a);
	return(0);
}