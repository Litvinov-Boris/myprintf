/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prostonehvataetmesta.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:12:40 by svivienn          #+#    #+#             */
/*   Updated: 2019/08/12 15:16:16 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    lfiksfinal()
{
    if (ld.i[2] == 32767)
		write(1, "inf", 3);
	else
		write(1, "-inf", 3);
}

void    fiksfinal()
{
    if (d.i == 0x7FF0000000000000)
		write(1, "inf", 3);
	else
		write(1, "-inf", 3);
}