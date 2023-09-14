#include "main.h"

int ft_strlen(char *str);

void print_result_strlen(int nb, char *str)
{
	if (nb == 0)
		printf("%s\n", "\033[1;32m<<<<<<< SUCCESS >>>>>>>\033[1;0m");
	else
	{
		printf("%s\n", "\033[1;31m>>>>>> FAILLURE <<<<<<<");
		printf("Valeur: %s\n", str);
		printf("ft_strlen = %d\n", ft_strlen(str));
		printf("strlen = %lu\n", strlen(str));
	}
}

int test_strlen(void)
{
	printf("%s\n", "\033[1;0m=======ft_strlen=======");
	if (ft_strlen("") != strlen(""))
		print_result_strlen(1, "");
	else
		print_result_strlen(0, "");
	usleep(100000);
	if (ft_strlen(" ") != strlen(" "))
		print_result_strlen(1, " ");
	else
		print_result_strlen(0, " ");
	usleep(100000);
	if (ft_strlen("1234567890") != strlen("1234567890"))
		print_result_strlen(1, "1234567890");
	else
		print_result_strlen(0, "1234567890");
	usleep(100000);
	if (ft_strlen("AZERTYUIOP") != strlen("AZERTYUIOP"))
		print_result_strlen(1, "AZERTYUIOP");
	else
		print_result_strlen(0, "AZERTYUIOP");
	usleep(100000);
	if (ft_strlen("azertyuiop") != strlen("azertyuiop"))
		print_result_strlen(1, "azertyuiop");
	else
		print_result_strlen(0, "azertyuiop");
	usleep(100000);
	if (ft_strlen("azert\nyuiop") != strlen("azert\nyuiop"))
		print_result_strlen(1, "azert\nyuiop");
	else
		print_result_strlen(0, "azert\nyuiop");
	usleep(100000);
	if (ft_strlen("azert\0yuiop") != strlen("azert\0yuiop"))
		print_result_strlen(1, "azert\0yuiop");
	else
		print_result_strlen(0, "azert\0yuiop");
	usleep(100000);
	if (ft_strlen("&é\"'(§è!çà)") != strlen("&é\"'(§è!çà)"))
		print_result_strlen(1, "&é\"'(§è!çà)");
	else
		print_result_strlen(0, "&é\"'(§è!çà)");
	usleep(100000);
	printf("%s\n", "=======================");
	return (0);
}