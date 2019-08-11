/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 07:58:43 by svivienn          #+#    #+#             */
/*   Updated: 2019/08/11 09:13:11 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    printnumber(t_format *inf, char *str, int zn, int zap)
{
	if (inf->width <= strlen(str) + zap)
	{
		preprint(zn, inf);
		write(1, str, strlen(str));
	}
	else if (inf->flag >> 2 & 1)
	{
		preprint(zn, inf);
		write(1, str, strlen(str));
		printspase(' ', inf->width - strlen(str) - zap);
	}
	else if (inf->flag >> 3 & 1)
	{
		preprint(zn, inf);
		printspase('0', inf->width - strlen(str) - zap);
		write(1, str, strlen(str));
	}
	else
	{
		printspase(' ', inf->width - strlen(str) - zap);
		preprint(zn, inf);
		write(1, str, strlen(str));
	}
}

void	preprint(int zn, t_format *inf)
{
	if (zn)
		write(1, "-", 1);
	else if (inf->flag >> 1 & 1)
		write (1, "+", 1);
	else if (inf->flag & 1)
		write (1, " ", 1);
}

void	printspase(char c, int i)
{
	while (i)
	{
		write(1, &c, 1);
		i--;
	}
}