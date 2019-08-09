/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writelongdouble.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:51:08 by svivienn          #+#    #+#             */
/*   Updated: 2019/08/09 16:06:03 by svivienn         ###   ########.fr       */
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