/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writefloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:48:11 by boris             #+#    #+#             */
/*   Updated: 2019/08/09 14:56:24 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long_value	*whole(int n)
{
	long_value *rez;
	long_value *rezerv;
	int j;

	if (!(rez = binpow(n, 2)))
		return (NULL);
	j = 52;
	while(--n >= 0 && --j >=0)
		if(d.i>>j & 1)
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
	return(rez);
}

int			normrez(long_value **x, int pow)
{
	int			i;
	int			*rez;
	long_value	*rezerv;

	if ((rez = (int*)malloc(sizeof(int) * pow)) == NULL)
		return (0);
	memset(rez, 0, sizeof(int) * pow);
	i = 0;
	while (++i && pow - i >= 0 && (*x)->size - i + 1 > 0)
		rez[pow - i] = (*x)->value[(*x)->size - i];
	free((*x)->value);
	(*x)->value = rez;
	(*x)->size = pow;
	if (!(rezerv = binpow(pow, 5)))
		return (0);
	if (!(sum(*x, rezerv)))
	{
		free_long_value(&rezerv);
		return (0);
	}
	(*x)->size = pow;
	free_long_value(&rezerv);
	return (1);
}

long_value	*fraction(int ot, int pow)
{
	long_value	*rez;
	int j;

	if ((rez = (long_value*)malloc(sizeof(*rez))) == NULL)
		return (NULL);
	if ((rez->value = (int*)malloc(sizeof(int))) == NULL)
	{
		free(rez);
		return (NULL);
	}
	rez->value[0] = (ot == 0) ? 5 : 0;
	pow += rez->value[0] == 5 ? 1 : 0;
	rez->size = 1;
	j = 52 - ot;
	while (--j >= 0)
	{
		if (d.i >> j & 1)
			if (!normrez(&rez, pow))
			{
				free_long_value(&rez);
				return (NULL);
			}
		pow++;
	}
	return (rez);
}