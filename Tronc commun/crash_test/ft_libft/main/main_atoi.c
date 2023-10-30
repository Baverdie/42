#include <stdio.h>
#include <unistd.h>

int ft_atoi(char *str);

void print_result_atoi(int nb, char *str)
{
	if (nb == 0)
		printf("%s\n", "\033[1;32m<<<<<<< SUCCESS >>>>>>>\033[1;0m");
	else
	{
		printf("%s\n", "\033[1;31m>>>>>> FAILLURE <<<<<<<");
		printf("Valeur: %s\n", str);
		printf("ft_atoi = %d\n", ft_atoi(str));
	}
}

int test_atoi(void)
{
	printf("%s\n", "\033[1;0m========ft_atoi========");
	usleep(100000);
	if (ft_atoi("") != 0)
		print_result_atoi(1, "");
	else
		print_result_atoi(0, "");
	usleep(100000);
	if (ft_atoi("0") != 0)
		print_result_atoi(1, "0");
	else
		print_result_atoi(0, "");
	usleep(100000);
	if (ft_atoi("1") != 1)
		print_result_atoi(1, "1");
	else
		print_result_atoi(0, "");
	usleep(100000);
	if (ft_atoi("-1") != -1)
		print_result_atoi(1, "-1");
	else
		print_result_atoi(0, "");
	usleep(100000);
	if (ft_atoi("   ") != 0)
		print_result_atoi(1, "   ");
	else
		print_result_atoi(0, "");
	usleep(100000);
	if (ft_atoi("   1") != 1)
		print_result_atoi(1, "   1");
	else
		print_result_atoi(0, "");
	usleep(100000);
	if (ft_atoi("   -1") != -1)
		print_result_atoi(1, "   -1");
	else
		print_result_atoi(0, "");
	usleep(100000);
	if (ft_atoi("    -+-1") != 1)
		print_result_atoi(1, "    -+-1");
	else
		print_result_atoi(0, "");
	usleep(100000);
	if (ft_atoi("    -+-+-+-1234567890") != 1234567890)
		print_result_atoi(1, "    -+-+-+-1234567890");
	else
		print_result_atoi(0, "");
	usleep(100000);
	if (ft_atoi("     -+-+-+46446adcsq4534") != -46446)
		print_result_atoi(1, "     -+-+-+46446adcsq4534");
	else
		print_result_atoi(0, "");
	usleep(100000);
	printf("%s\n", "=======================");
	return (0);
}