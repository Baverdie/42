#include <stdio.h>

int	ft_atoi(char *str);

void	print_result(int nb, char *str)
{
	int	i;

	i = 0;
	if (nb == 0)
		printf("%s\n", "\033[1;32m<<<<<<< SUCCESS >>>>>>>\033[1;0m");
	else
	{
		printf("%s\n", "\033[1;31m>>>>>> FAILLURE <<<<<<<");
		printf("Valeur: "); 
		while (str[i])
		{
			if (str[i] < 48 || str[i] > 57)
				printf("%c", str[i]);
			else if (str[i] >= 48 && str[i] <= 57)
				printf("%c", str[i]);
			i++;
		}
		printf("\nft_atoi = %d\n", ft_atoi(str));
	}
}

int	main(void)
{
	printf("%s\n", "\033[1;0m========ft_atoi========");
	if (ft_atoi("") != 0)
		print_result(1, "");
	else
		print_result(0, "");
	if (ft_atoi("0") != 0)
		print_result(1, "0");
	else
		print_result(0, "");
	if (ft_atoi("1") != 1)
		print_result(1, "1");
	else
		print_result(0, "");
	if (ft_atoi("-1") != -1)
		print_result(1, "-1");
	else
		print_result(0, "");
	if (ft_atoi("   ") != 0)
		print_result(1, "   ");
	else
		print_result(0, "");
	if (ft_atoi("   1") != 1)
		print_result(1, "   1");
	else
		print_result(0, "");
	if (ft_atoi("   -1") != -1)
		print_result(1, "   -1");
	else
		print_result(0, "");
	if (ft_atoi("    -+-1") != 1)
		print_result(1, "    -+-1");
	else
		print_result(0, "");
	if (ft_atoi("    -+-+-+-1234567890") != 1234567890)
		print_result(1, "    -+-+-+-1234567890");
	else
		print_result(0, "");
	if (ft_atoi("     -+-+-+46446adcsq4534") != -46446)
		print_result(1, "     -+-+-+46446adcsq4534");
	else
		print_result(0, "");
	printf("%s\n", "=======================");
}
