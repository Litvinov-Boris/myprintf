/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writelongdouble.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:30:52 by svivienn          #+#    #+#             */
/*   Updated: 2019/08/08 17:34:56 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long_value  *lwhole(int n)
{
    long_value *rez;
    long_value *rezerv;
    int j;

    rez = malloc(sizeof(*rez));
	rez->value = malloc(sizeof(int));
    rez->value[0] = 0;
    rez->size = 1;
    j = 64;
    n++;
    while (--j >= 0 && --n >= 0)
        if (ld.man>>j & 1)
        {
            rezerv = binpow(n, 2);
            sum(rez, rezerv);
            free(rezerv->value);
            free(rezerv);
        }
    return (rez);
}

long_value  *lfraction(int ot, int step)
{
    long_value *rez;
    int j;

    j = 64 - ot - 1;
    rez = malloc(sizeof(*rez));
    rez->value = malloc(sizeof(int));
    rez->value[0] = 0;
    rez->size = 1;
    while(--j >= 0)
    {
        if(ld.man>>j & 1)
            normrezerv(&rez, step);
        step++;
    }
    return (rez);
}