/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writelongdouble.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:51:08 by svivienn          #+#    #+#             */
/*   Updated: 2019/08/11 05:34:51 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int         initlwhole(long_value **rez)
{
	if ((*rez = (long_value*)malloc(sizeof(*rez))) == NULL)
		return (0);
	if (((*rez)->value = (int*)malloc(sizeof(int))) == NULL)
	{
		free(rez);
		return (0);
	}
	(*rez)->value[0] = 0;
	(*rez)->size = 1;
	return (1);
}

long_value  *lwhole(int n)
{
	long_value  *rez;
	long_value  *rezerv;
	int j;

	if (!initlwhole(&rez))
		return (0);
	j = 64;
	n++;
	while (--j >= 0 && --n >= 0)
		if (ld.man >> j & 1)
		{
			if (!(rezerv = binpow(n, 2)))
			{
				free_long_value(&rez);
				return (NULL);
			}
			if (!(sum(rez,rezerv)))
			{
				free_long_value(&rez);
				free_long_value(&rezerv);
				return (NULL);
			}
			free_long_value(&rezerv);
		}
	return (rez);
}

long_value  *lfraction(int ot, int pow)
{
	long_value *rez;
	int j;

	if (!initlwhole(&rez))
		return (0);
	j = 64 - ot - 1;
	while(--j >= 0)
    {
        if(ld.man>>j & 1)
           if (!normrez(&rez, pow))
			{
				free_long_value(&rez);
				return (NULL);
			}
        pow++;
    }
	return (rez);
}

char	*ldoubletostr(int prec)
{
	long_value	*wh;
	long_value	*frc;
	char		*str;

	if (longdexp() >= 0)
	{
		wh = lwhole(longdexp());
		frc = lfraction(longdexp(), 1);
	}
	else
	{
		if (!initlwhole(&wh))
			return (NULL);
		frc = lfraction(0, -(longdexp()));
	}
	if (!normnumber(&wh, &frc, prec))
		return(NULL);
	if (!(str = doubletonumber(wh, frc)))
		return(freenumber(&wh, &frc));
	return(str);
}