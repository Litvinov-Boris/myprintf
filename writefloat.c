/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writefloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:48:11 by boris             #+#    #+#             */
/*   Updated: 2019/08/07 18:36:56 by boris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long_value	*whole(int n)
{
	long_value *rez;
	long_value *rezerv;
	int j;
	int *ret;

	rez = binpow(n, 2);
	j = 52;
	while(--n >= 0 && --j >=0)
	{
		if(d.i>>j & 1)
			{
				rezerv = binpow(n, 2);
				sum(rez,rezerv);
				free(rezerv->value);
				free(rezerv);
			}
	}
	return(rez);
}

long_value *fraction(int ot, int step)
{
	long_value *rez;
	int j;

	j = 52 - ot;
	rez = malloc(sizeof(*rez));
	rez->value = malloc(sizeof(int));
	rez->value[0] = (ot == 0) ? 5 : 0;
	if (rez->value[0] == 5)
		step++;
	rez->size = 1;
	while (--j >= 0)
	{
		if (d.i>>j & 1)
			normrezerv(&rez, step);
		step++;
	}
	return(rez);
}

void	normrezerv(long_value **x, int step)
{
	int i;
	int *rez;
	long_value *rezerv;

	i = 1;
	rez = malloc(sizeof(int) * step);
	//поменять на ft_memset
	memset(rez, 0, sizeof(int) * step);
	while(step - i >= 0 && (*x)->size - i + 1 > 0)
	{
		rez[step - i] = (*x)->value[(*x)->size - i];
		i++;
	}
	free((*x)->value);
	(*x)->value = rez;
	(*x)->size = step;
	rezerv = binpow(step, 5);
	sum(*x, rezerv);
	(*x)->size = step;
	free(rezerv->value);
	free(rezerv);
}

/*char *dobltoa()
{
	if (d.i == 9218868437227405312 || d.i == 18442240474082181120)
		return (d.i == 9218868437227405312 ? "inf" : "-inf");
	else if (dexp() == 2047)
		return ("nan");
}*/