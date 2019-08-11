#include <stdio.h>
#include <stdint.h>
#include "ft_printf.h"

int main(void)
{
	ld.ld = 9.6341541;
	t_format a;
	a.flag = 0;
	a.flag |=0x01;
	//a.flag |=0x02;
	a.flag |=0x04;
	//a.flag |=0x08;
	a.flag |=0x10;
	a.prec = 10;
	a.width = 20;
	char *str = ldoubletostr(a.prec);
	printnumber(&a,str,(int)(ld.ld < 0), (int)(ld.ld <0 || a.flag & 1 || a.flag>>1 & 1));
	return(0);
}