/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolsforkatsuba.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 20:21:49 by boris             #+#    #+#             */
/*   Updated: 2019/08/05 23:53:13 by boris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initkaratsuba(karatsuba **term, long_value *a, long_value *b)
{
	*term = malloc(sizeof(**term));
	(*term)->am = malloc(sizeof(long_value));
	(*term)->as = malloc(sizeof(long_value));
	(*term)->bm = malloc(sizeof(long_value));
	(*term)->bs = malloc(sizeof(long_value));
	(*term)->am->size = (a->size + 1) / 2;
	(*term)->as->size = a->size / 2;
	(*term)->bm->size = (b->size + 1) / 2;
	(*term)->bs->size = a->size / 2;
	(*term)->am->value = a->value;
	(*term)->as->value = a->value + (*term)->am->size;
	(*term)->bm->value = b->value;
	(*term)->bs->value = b->value + (*term)->bm->size;
}

void	freelongvalue(long_value **term)
{
	free((*term)->value);
	free(*term);
}

void	freeterms(long_value **term1, long_value **term2, long_value **term3)
{
	freelongvalue(term1);
	freelongvalue(term2);
	freelongvalue(term3);
}

void	freekaratsuba(karatsuba **term)
{
	free((*term)->am);
	free((*term)->as);
	free((*term)->bm);
	free((*term)->bs);
	free(*term);
}