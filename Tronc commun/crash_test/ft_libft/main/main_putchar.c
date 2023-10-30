#include <unistd.h>

void	ft_putchar(char c);

int	main(void)
{
	char	i;

	i = 33;
	while (i < 127)
	{
		ft_putchar(i);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}