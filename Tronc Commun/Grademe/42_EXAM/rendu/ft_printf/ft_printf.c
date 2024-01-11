#include <stdarg.h>
#include <unistd.h>

int	putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
		write(1, &str[i], 1);
	return (i);
}

int	putnbr(long long int nb)
{
	int	cntr;

	cntr = 0;
	if (nb < 0)
	{
		nb *= -1;
		cntr += putchar('-');
	}
	if (nb < 10)
		cntr += putchar(nb + 48);
	else
	{
		cntr += putnbr(nb / 10);
		cntr += putchar(nb % 10 + 48);
	}
	return (cntr);
}

int	putnbr_hexa(unsigned long long int nb)
{
	int	cntr;
	char	*base;

	cntr = 0;
	base = "0123456789abcdef";
	if (nb < 16)
		cntr += putchar(base[nb]);
	else
	{
		cntr += putnbr(nb / 16);
		cntr += putchar(base[nb % 16]);
	}
	return (cntr);
}

int	ft_printf(const char *s, ... )
{
	va_list arg;
	int	i;
	int	j;

	va_start(arg, s);
	if (!s)
		return (-1);
	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] == '\0')
		{
			i++;
			if (s[i] == 's')
				j += putstr(va_arg(arg, char *));
			else if (s[i] == 'd')
				j += putnbr(va_arg(arg, long long int));
			else if (s[i] == 'x')
				j += putnbr_hexa(va_arg(arg, unsigned long long int));
			else
				j += putchar(s[i]);
		}
		else
			j += putchar(s[i]);
		i++;
	}
	va_end(arg);
	return (j);
}


int	main()
{
	ft_printf("%s\n", "toto");
}