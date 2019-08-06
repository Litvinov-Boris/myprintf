/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:49:45 by boris             #+#    #+#             */
/*   Updated: 2019/08/06 18:17:12 by svivienn         ###   ########.fr       */
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

int			ft_printf(const char *format, ...);
int			dexp();
void		simplecom(long_value *a, long_value *b);
void		normalize(long_value *x);
long_value	*binpow(int n, int base);
void		sum(long_value *a, long_value *b);
int			*whole(int n);
int *fraction(int ot, int step);
void	normrezerv(long_value **x, int step);

#endif