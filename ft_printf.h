/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:49:45 by boris             #+#    #+#             */
/*   Updated: 2019/08/12 15:18:21 by svivienn         ###   ########.fr       */
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

typedef struct		s_format
{
	char			flag;
	unsigned int	width;
	unsigned int	prec;
	char			length;
	char			type;
}					t_format;

int			dexp();
int			longdexp();
void 		free_long_value(long_value **x);
int			zerotofrc(long_value *frc, int prec);

void        normalize(long_value *x);
int         sum(long_value *a, long_value *b);
int         simplecom(long_value *a, long_value *b);
int			initbinpow(long_value **rez, long_value **pow, int base);
long_value  *binpow(int n, int base);

long_value	*whole(int n);
int			normrez(long_value **x, int pow);
long_value	*fraction(int ot, int pow);
char		*wholetostr(long_value *wh);
char		*doubletonumber(long_value *wh, long_value *frc, int prec);

int         initlwhole(long_value **rez);
long_value  *lwhole(int n);
long_value  *lfraction(int ot, int pow);
char		*ldoubletostr(int prec);
int			finalprintnahoild(t_format *inf);

int			formfraction(int prec, long_value *frc);
int			normfraction(long_value *frc);
int			normwhole(long_value *wh, int plus);
char 		*freenumber(long_value **wh, long_value **frc);
int			normnumber(long_value **wh, long_value **frc, int prec);
char		*doubletostr(int prec);

void		preprint(int zn, t_format *inf);
void		printspase(char c, int i);
void		printnumber(t_format *inf, char *str, int zn, int zap);
char		*zerostr(int prec);
int			finalprintnahoid(t_format *inf);

void    lfiksfinal();
void    fiksfinal();

#endif