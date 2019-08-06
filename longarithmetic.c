/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longarithmetic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 20:24:30 by boris             #+#    #+#             */
/*   Updated: 2019/08/06 16:38:07 by boris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        normalize(long_value *x)
{
	unsigned long long int i;

	i = -1;
	while (++i < x->size)
	{
		if (x->value[i] >= 10)
		{
			x->value[i + 1] += x->value[i] / 10;
			x->value[i] %= 10;
		}
	}
	while (x->value[x->size - 1] == 0)
		x->size--;
}

void simplecom(long_value *a, long_value *b)
{
	int *rez;
	unsigned long long int i;
	unsigned long long int j;

	rez= malloc(sizeof(*rez) * (a->size + b->size));
	//поменять на ft_memset
	memset(rez, 0, sizeof(*rez) * (a->size + b->size));
	i = -1;
	while (++i < a->size)
	{
		j = -1;
		while(++j < b->size)
		{
			rez[i + j] += a->value[i] * b->value[j];
		}
	}
	free(a->value);
	a->value = rez;
	a->size = (a->size + b->size);
	normalize(a);
}

long_value *binpow(int n, int base)
{
	long_value *rez;
	long_value *pow;

	rez = malloc(sizeof(*rez));
	rez->value = malloc(sizeof(int));
	rez->value[0] = 1;
	rez->size = 1;
	pow = malloc(sizeof(*pow));
	pow->value = malloc(sizeof(int));
	pow->value[0] = base;
	pow->size = 1;
	while (n)
	{
		if(n & 1)
			simplecom(rez, pow);
		simplecom(pow, pow);
		n>>=1;
	}
	free(pow->value);
	free(pow);
	return (rez);
}

void	sum(long_value *a, long_value *b)
{
	unsigned long long int i;
	int *s;
	
	s = malloc(sizeof(int) * (a->size > b->size ? a->size +1 : b->size + 1));
	memset(s, 0, sizeof(int) * (a->size > b->size ? a->size +1 : b->size + 1));
	i = -1;
	while(++i < a->size)
		s[i] = a->value[i];
	i = -1;
	while(++i < b->size)
		s[i] = s[i] + b->value[i];
	free(a->value);
	a->value = s;
	a->size = (a->size > b->size ? a->size +1 : b->size + 1);
	normalize(a);
}