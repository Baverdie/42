/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:55:10 by bastienverd       #+#    #+#             */
/*   Updated: 2024/07/02 16:58:55 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.h"

typedef unsigned char uint8_t;

class PhoneBook {
	private:
		void	Add();
		void	Exit();
		void	Search();

		Contact	_contact[8];
		uint8_t	_index;

	public:
		PhoneBook(void);
			int	Command(const std::string &command);
};

bool	CheckInput(std::string &rep);
std::string CheckLength(const std::string &str);
