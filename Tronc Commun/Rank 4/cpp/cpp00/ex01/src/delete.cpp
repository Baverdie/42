/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:56:11 by basverdi          #+#    #+#             */
/*   Updated: 2024/06/28 20:09:55 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

void	printAllContact(Contact *contact) {

	for (int i = 0; i < 8 && !contact[i].GetFirstName().empty(); i++) {
		std::string title = "~~~~~~~~~ Contact #" + std::to_string(i + 1) + " ~~~~~~~~~";
		int titleLength = title.length();
		std::string endContact = std::string(titleLength, '~');
		std::cout << BOLD << MAGENTA << title << "\n"
				  << RESET
				  << BOLD << MAGENTA << "│" << CYAN << " First Name : " << RESET << std::left << std::setw(titleLength - 16) << CheckLength(contact[i].GetFirstName()) << BOLD << MAGENTA << "│\n"
				  << RESET
				  << BOLD << MAGENTA << "│" << CYAN << " Last Name : " << RESET << std::left << std::setw(titleLength - 15) << CheckLength(contact[i].GetLastName()) << BOLD << MAGENTA << "│\n"
				  << RESET
				  << BOLD << MAGENTA << "│" << CYAN << " Nickname : " << RESET << std::left << std::setw(titleLength - 14) << CheckLength(contact[i].GetNickname()) << BOLD << MAGENTA << "│\n"
				  << RESET
				  << BOLD << MAGENTA << "│" << CYAN << " Phone Number : " << RESET << std::left << std::setw(titleLength - 18) << CheckLength(contact[i].GetPhoneNumber()) << BOLD << MAGENTA << "│\n"
				  << RESET
				  << BOLD << MAGENTA << "│" << CYAN << " Darkest Secret : " << RESET << std::left << std::setw(titleLength - 20) << CheckLength(contact[i].GetDarkestSecret()) << BOLD << MAGENTA << "│\n"
				  << BOLD << MAGENTA << endContact
				  << RESET
				  << std::endl;
	}
	std::cout << std::endl;
}
