#include "main.h"

int ft_strcmp(char *s1, char *s2);

void print_result_strcmp(int nb, char *s1, char *s2)
{
	if (nb == 0)
		printf("%s\n", "\033[1;32m<<<<<<< SUCCESS >>>>>>>\033[1;0m");
	else
	{
		printf("%s\n", "\033[1;31m>>>>>> FAILLURE <<<<<<<");
		printf("Valeur: \"%s\" \"%s\"\n", s1, s2);
		printf("ft_strlen = %d\n", ft_strcmp(s1, s2));
		printf("strlen = %lu\n", strcmp(s1, s2));
	}
}

int test_strcmp(void)
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