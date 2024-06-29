/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:49:18 by bastienverd       #+#    #+#             */
/*   Updated: 2024/06/28 20:18:39 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

static bool	CheckFormat(const std::string &str, const std::string &type) {
	if (str.empty()) {
		std::cout << BOLD << RED << type << " can't be empty\n" << RESET << std::endl;
		return (true);
	}
	return (false);
}

void	PhoneBook::Add(void) {
	std::string	input;

	if (_index == 8 || !_contact[_index].GetFirstName().empty()) {
		std::cout << BOLD << RED << "The PhoneBook is full, the oldest contact will be replaced." << RESET << "\nDo you want to continue (Y/N): ";
		CheckInput(input);
		if (input.compare("Y") != 0 && input.compare("y") != 0 && input.compare("yes") != 0 && input.compare("N") != 0 && input.compare("n") != 0 && input.compare("no") != 0) {
			std::cout << BOLD << RED << "Invalid input\n" << RESET << std::endl;
			return;
		}
		else if (input.compare("N") == 0 || input.compare("n") == 0 || input.compare("no") == 0) {
			std::cout << std::endl;
			return;
		}
		if (_index == 8)
			_index = 0;
	}
	std::cout << "┌────────────── New contact ──────────────┐" << std::endl;
	std::cout << "│ First name : ";
	CheckInput(input);
	if (CheckFormat(input, "First name"))
		return;
	_contact[_index].SetFirstName(input);
	std::cout << "│ Last name : ";
	CheckInput(input);
	if (CheckFormat(input, "Last name"))
		return;
	_contact[_index].SetLastName(input);
	std::cout << "│ Nickname : ";
	CheckInput(input);
	if (CheckFormat(input, "Nickname"))
		return;
	_contact[_index].SetNickname(input);
	std::cout << "│ Phone number : ";
	CheckInput(input);
	if (CheckFormat(input, "Phone number"))
		return;
	_contact[_index].SetPhoneNumber(input);
	std::cout << "│ Darkest secret : ";
	CheckInput(input);
	if (CheckFormat(input, "Darkest secret"))
		return;
	_contact[_index].SetDarkestSecret(input);
	_index++;
	std::cout << "└─────────────────────────────────────────┘\n" << RESET << std::endl;
	// printAllContact(_contact);
}
