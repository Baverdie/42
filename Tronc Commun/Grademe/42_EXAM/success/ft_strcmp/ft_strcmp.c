int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;
	int	diff;

	if (!s1 || !s2)
		return (0);
	i = 0;
	diff = 0;
	while (!diff && (s1[i] || s2[i]))
	{
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	return (diff);
}
