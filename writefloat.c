/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writefloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:48:11 by boris             #+#    #+#             */
/*   Updated: 2019/08/06 16:38:28 by boris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int *whole(int n)
{
    long_value *rez;
    long_value *rezerv;
    int j;
    int *ret;

    rez = binpow(n, 2);
    j = 52;
    while(--n >= 0)
    {
        if(d.i>>(j) & 1)
            {
                rezerv = binpow(n, 2);
                sum(rez,rezerv);
                free(rezerv->value);
                free(rezerv);
            }
    }
    ret = malloc(sizeof(int) * rez->size);
    memcpy(ret, rez->value, sizeof(int) * rez->size);
    free(rez->value);
    free(rez);
    return(ret);
}