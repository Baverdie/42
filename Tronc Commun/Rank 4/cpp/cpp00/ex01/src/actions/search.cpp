/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:07:53 by bastienverd       #+#    #+#             */
/*   Updated: 2024/07/02 19:39:50 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.h>
#include <cctype>
#include <cstdlib>
#include <string>
#include <iostream>
#include <climits>
#include <iomanip>

std::string RightAlign(const std::string &text, int width){
	int len = text.length();
	if (len >= width)
		return text;
	int padding = (width - len);
	return std::string(padding, ' ') + text;
}

std::string CheckLength(const std::string &str) {
	if (str.length() > LENGTH_COLUMNS)
		return (str.substr(0, LENGTH_COLUMNS - 1) + ".");
	return (str);
}

static bool	printTable(Contact *contact) {
	if (contact[0].GetFirstName().empty()) {
		std::cout << "No contact found\n" << std::endl;
		return (true);
	}
	std::cout << "┌──────────┬──────────┬──────────┬──────────┐\n"
			  << "│  INDEX   │FIRST NAME│LAST  NAME│ NICKNAME │\n"
			  << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
	for (int i = 0; i < 8 && !contact[i].GetFirstName().empty(); i++) {
		std::cout << "│         " << i + 1 << "│"
				  << RightAlign(CheckLength(contact[i].GetFirstName()), LENGTH_COLUMNS) << "│"
				  << RightAlign(CheckLength(contact[i].GetLastName()), LENGTH_COLUMNS) << "│"
				  << RightAlign(CheckLength(contact[i].GetNickname()), LENGTH_COLUMNS);
		if (i == 7 || contact[i + 1].GetFirstName().empty())
			std::cout << "│\n└──────────┴──────────┴──────────┴──────────┘\n" << std::endl;
		else
			std::cout << "│\n├──────────┼──────────┼──────────┼──────────┤" << std::endl;
	}
	return (false);
}

static void	DisplayContact(std::string &input, Contact *contact) {
	int	index = std::atoi(input.c_str()) - 1;

	if (index < 0 || index > 7 || contact[index].GetFirstName().empty()) {
		std::cout << RED << "Contact not found\n" << RESET << std::endl;
		return ;
	}
	std::cout << "┌────────────────────────────────────────┐"
			  << "\n│ First Name : " + contact[index].GetFirstName()
			  << "\n│ Last Name : " + contact[index].GetLastName()
			  << "\n│ Nickname : " + contact[index].GetNickname()
			  << "\n│ Phone Number : " + contact[index].GetPhoneNumber()
			  << "\n│ Darkest Secret : " + contact[index].GetDarkestSecret()
			  << "\n└────────────────────────────────────────┘\n"
			  << std::endl;
}

void	PhoneBook::Search(void) {
	std::string	input;

	if (printTable(_contact))
		return ;
	std::cout << "Enter the index of the contact you want to see : ";
	CheckInput(input);
	DisplayContact(input, _contact);
}
