#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((i == 0 || (i > 0 && s[i - 1] == c)) && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static int	ft_len_words(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**ft_free(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

static char	**ft_tab(char **tab, const char *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			k = 0;
			tab[j] = malloc((ft_len_words(&s[i], c) + 1) * sizeof(char));
			if (!tab[j])
				ft_free(tab, j);
			while ((s[i] && s[i] != c))
				tab[j][k++] = s[i++];
			tab[j][k] = '\0';
			j++;
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	return (ft_tab(tab, s, c));
}

int main(int argc, char **argv)
{
	char **tab;
	int i;

	i = 0;
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		while (tab[i])
			i++;
		i--;
		while (i >= 0)
		{
			ft_putstr(tab[i]);
			if (i > 0)
				write(1, " ", 1);
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
