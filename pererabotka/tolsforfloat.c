/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolsforfloat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 20:14:40 by boris             #+#    #+#             */
/*   Updated: 2019/08/09 13:10:17 by svivienn         ###   ########.fr       */
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