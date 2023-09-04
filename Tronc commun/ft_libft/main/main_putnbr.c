/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:49:07 by basverdi          #+#    #+#             */
/*   Updated: 2023/09/04 22:03:08 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putnbr(int n);

void exect()
{
	int	nb;

	nb = -42;
	FILE* fichier = NULL;
	fichier = fopen("test_putnbr.txt", "w");
	if (fichier != NULL) {
		while (nb <= 420) {
			fprintf(fichier, "%d\n", ft_putnbr(nb));
			nb += 3;
		}
		fclose(fichier);
	}
}

void	print_result(int nb, int n)
{
	if (nb == 0)
		printf("%s\n", "\033[1;32m<<<<<<< SUCCESS >>>>>>>\033[1;0m");
	else
	{
		printf("%s\n", "\033[1;31m>>>>>> FAILLURE <<<<<<<");
		printf("Valeur: ");
		printf("\nft_putnbr = %d\n", n);
	}
}

int	main(void) {
	int	count;
	int	x;
	int	y;

	exect();
	FILE* t = NULL;
	t = fopen("test_putnbr.txt", "r");
	FILE* r = NULL;
	r = fopen("putnbr.txt", "r");
	count = 0;
	x = 0;
	y = 0;
	if (t != NULL && r != NULL) {
		printf("%s\n", "\033[1;0m=======ft_putnbr=======");
	 	while (x != EOF && y != EOF) {
			x = fgetc(t);
 			y = fgetc(r);
	 		if (x != y)
				print_result(1, -42 + count);
			if (x == '\n' && y == '\n')
	 			count++;
		}
		printf("%s\n", "\033[1;0m=======================");
	}
	fclose(t);
	fclose(r);
}