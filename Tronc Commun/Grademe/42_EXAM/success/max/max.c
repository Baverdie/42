int		max(int* tab, unsigned int len)
{
	unsigned int	i;
	int	res;

	i = 0;
	res = 0;
	if (!tab)
		return (res);
	while (tab[i] && i <= len - 1)
	{
		if (tab[i] > res)
			res = tab[i];
		i++;
	}
	return (res);
}
