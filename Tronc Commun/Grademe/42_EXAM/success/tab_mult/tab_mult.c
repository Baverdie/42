#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	atoi(char *str)
{
	int i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb);
}

void	ft_putnbr(int nb)
{
	if (nb < 10)
		ft_putchar(nb + 48);
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int	i;
	int	nb;
	int	res;
	int len;

	i = 1;
	nb = 0;
	res = 0;
	if (argc == 2)
	{
		nb = atoi(argv[1]);
		while (i < 10)
		{
			ft_putchar((char)i + 48);
			write(1, " x ", 3);
			write(1, argv[1], ft_strlen(argv[1]));
			write(1, " = ", 3);
			res = i * nb;
			ft_putnbr(res);
			ft_putchar('\n');
			i++;
		}
	}
	else
		ft_putchar('\n');
	return 0;
}
