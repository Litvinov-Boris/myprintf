/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolsforfloat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 20:14:40 by boris             #+#    #+#             */
/*   Updated: 2019/08/11 05:36:52 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int dexp()
{
    int i;

    i = ((d.i >> 52) & 2047) - 1023;
    return (i);
}

int longdexp()
{
    int i;
    
    i = (ld.i[2] & 32767) - 16383;
    return (i);
}

void free_long_value(long_value **x)
{
    free((*x)->value);
    free(*x);
}

char	*doubletostr(int prec)
{
	long_value	*wh;
	long_value	*frc;
	char		*str;

	if (dexp() >= 0)
	{
		wh = whole(dexp());
		frc = fraction(dexp(), 1);
	}
	else
	{
		if (!initlwhole(&wh))
			return (NULL);
		frc = fraction(0, -(dexp()));
	}
	if (!normnumber(&wh, &frc, prec))
		return(NULL);
	if (!(str = doubletonumber(wh, frc)))
		return(freenumber(&wh, &frc));
	return(str);
}
