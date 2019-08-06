/*long_value  *karatsubacom(long_value *a, long_value *b)
{
	karatsuba	*term;
	long_value	*rez;
	long_value	*term1;
	long_value	*term2;
	long_value	*term3;
	
	if (a->size < 4 && b->size < 4)
		return (simplecom(a, b));
	else
	{
		initkaratsuba(&term, a, b);
		rez = karatsubacom(term->am, term->bm);
		term1 = karatsubacom(term->am, term->bs);
		term2 = karatsubacom(term->as, term->bm);
		term3 = sum(term1, term2);
		stic(rez, term3);
		freelongvalue(&term1);
		term1 = karatsubacom(term->as, term->bs);
		stic(rez, term1);
		freeterms(&term1, &term2, &term3);
		freekaratsuba(&term);
		return(rez);
	}
}

long_value  *sum(long_value *a, long_value *b)
{
	long_value *s;
	unsigned long long int i;

	s = malloc(sizeof(long_value));
	s->size = a->size > b->size ? a->size + 1 : b->size + 1;
	s->value = malloc(sizeof(long_value) * s->size);
	//ft_memset
	memset(s->value, 0, sizeof(*(s->value)) * s->size);
	i = -1;
	while (++i < s->size)
	{
		s->value[i] = a->value[i] + b->value[i];
	}
	normalize(s);
	return (s);
}

void        stic(long_value *a, long_value *b)
{
	int *rez;
	unsigned long long int i;

	rez = malloc(sizeof(int) * a->size + b->size);
	i = -1;
	while (++i < a->size)
		rez[i] = a->value[i];
	i--;
	while (++i < a->size + b->size)
		rez[i] = b->value[i - a->size];
	free(a->value);
	a->value = rez;
	a->size = a->size + b->size;
}*/