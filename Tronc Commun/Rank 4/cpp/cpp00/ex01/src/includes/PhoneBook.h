/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:55:10 by bastienverd       #+#    #+#             */
/*   Updated: 2024/06/26 19:14:21 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.h"

typedef unsigned char uint8_t;

class PhoneBook {
	private:
		void	Add();
		void	Exit();

		Contact	_contact[8];
		uint8_t	_index : 3;

	public:
		PhoneBook(void);
			int	Command(const std::string &command);
};

void	printAllContact(Contact *contact);
bool	CheckInput(std::string &rep);
