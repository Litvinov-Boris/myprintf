/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:49:45 by boris             #+#    #+#             */
/*   Updated: 2019/08/09 16:04:50 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
//#include <stdint.h>

union doubletoint
{
	double d;
	unsigned long long int i;
}d;

union ldoubletoint
{
	long double ld;
	int i[3];
	unsigned long long int man;
}ld;


typedef struct              long_value
{
	int                     *value;
	unsigned long long int  size;
}                           long_value;

typedef struct  karatsuba
{
	long_value	*am;
	long_value	*as;
	long_value  *bm;
	long_value  *bs;
}               karatsuba;

int			dexp();
int			longdexp();
void 		free_long_value(long_value **x);

void        normalize(long_value *x);
int         sum(long_value *a, long_value *b);
int         simplecom(long_value *a, long_value *b);
int			initbinpow(long_value **rez, long_value **pow, int base);
long_value  *binpow(int n, int base);

long_value	*whole(int n);
int			normrez(long_value **x, int pow);
long_value	*fraction(int ot, int pow);

int         initlwhole(long_value **rez);
long_value  *lwhole(int n);

#endif