/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:49:27 by boris             #+#    #+#             */
/*   Updated: 2019/08/05 20:28:47 by boris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	int lenght;
	va_list ap;
	
	va_start(ap, format);
	lenght = ft_dvprintf(format, ap);
	va_end(ap);
	return (lenght);
}