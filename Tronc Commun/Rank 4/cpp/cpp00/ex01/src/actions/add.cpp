/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:49:18 by bastienverd       #+#    #+#             */
/*   Updated: 2024/06/26 16:21:52 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

void	PhoneBook::Add(void) {
	std::string	input;

	std::cout << "New contact" << std::endl;
	std::cout << "First name : ";
	CheckInput(input);
	_contact[_index].SetFirstName(input);
	std::cout << "Last name : ";
	CheckInput(input);
	_contact[_index].SetLastName(input);
	std::cout << "Nickname : ";
	CheckInput(input);
	_contact[_index].SetNickname(input);
	std::cout << "Phone number : ";
	CheckInput(input);
	_contact[_index].SetPhoneNumber(input);
	std::cout << "Darkest secret : ";
	CheckInput(input);
	_contact[_index].SetDarkestSecret(input);
	_index++;
}