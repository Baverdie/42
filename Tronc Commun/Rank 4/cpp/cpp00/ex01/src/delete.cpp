/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:56:11 by basverdi          #+#    #+#             */
/*   Updated: 2024/06/26 19:19:25 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

void	printAllContact(Contact *contact) {
    for (int i = 0; i < 8 && !contact[i].GetFirstName().empty(); i++) {
		std::cout  <<  "~~~~~~~~ Contact #"  << i
				<< " ~~~~~~~~\n" 
				<< "First Name : " 
				<< contact[i].GetFirstName() 
				<< "\nLast Name : " 
				<< contact[i].GetLastName() 
				<< "\nNickname : " 
				<< contact[i].GetNickname() 
				<< "\nPhone Number : " 
				<< contact[i].GetPhoneNumber() 
				<< "\nDarkest Secret : " 
				<< contact[i].GetDarkestSecret() 
				<< std::endl;
	}
	std::cout << std::endl;
}
