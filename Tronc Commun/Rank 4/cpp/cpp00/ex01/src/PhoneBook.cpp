/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:27:46 by basverdi          #+#    #+#             */
/*   Updated: 2024/06/27 15:14:10 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "includes/PhoneBook.h"


PhoneBook::PhoneBook(void) : _index(0) {}

bool	CheckInput(std::string &rep) {
	getline(std::cin, rep);
	return std::cin.eof();
}

int	PhoneBook::Command(const std::string &command) {
	if (command.compare("HELP") == 0)
		std::cout << "ADD : Add a new contact\nSEARCH : Search a contact\nEXIT : Exit the program\n" << std::endl;
	else if (command.compare("ADD") == 0)
		Add();
	else if (command.compare("SEARCH") == 0)
		Search();
	else if (command.compare("EXIT") == 0) {
		Exit();
		return (1);
	} else
		std::cout << RED << "Command not found (type HELP for more information)\n" << RESET << std::endl;
	return (0);
}

int	main() {
	PhoneBook	phoneBook;
	std::string	input;

	for (;;) {
		std::cout << "Enter command : ";
		if (CheckInput(input))
			break;
		if (phoneBook.Command(input))
			break;
	}
}
