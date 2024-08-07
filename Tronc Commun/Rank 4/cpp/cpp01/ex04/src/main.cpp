/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:07:38 by basverdi          #+#    #+#             */
/*   Updated: 2024/08/07 17:37:51 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string.h>

int	main(int ac, char **av)
{
	char *filename;
	char *s1;
	char *s2;

	if (ac == 4)
	{
		filename = av[1];
		s1 = av[2];
		s2 = av[3];
		strcat(filename, ".replace");
		std::ofstream fio(filename, std::ios::in);
		std::ofstream outfile (filename);
		outfile << fio << std::endl;
		fio.close();
	}
	else
		std::cout << "Bad arguments" << std::endl;
}
