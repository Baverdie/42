/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:27:46 by basverdi          #+#    #+#             */
/*   Updated: 2024/06/25 19:31:06 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "includes/PhoneBook.h"

int	check_input() {
	std::string	rep;

	getline(std::cin, rep);
	if (rep.compare("HELP") == 0) {
		std::cout << "ADD, SEARCH, or EXIT\n" << std::endl;
		std::cout << "Enter command : ";
		return (0);
	} else if (rep.compare("ADD") == 0) {
		return (0);
	} else if (rep.compare("EXIT") == 0) {
		std::cout << "See you soon..." << std::endl;
		return (1);
	}
	return (0);
}

int	main() {
	std::cout << "Enter command : ";
	for (; ;) {
		if (check_input())
			break;
	}
}
