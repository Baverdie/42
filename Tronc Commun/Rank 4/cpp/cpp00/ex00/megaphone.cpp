/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 23:46:04 by basverdi          #+#    #+#             */
/*   Updated: 2024/06/25 13:07:43 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int __attribute__((unused)) ac, char **av) {
	if (!*++av)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (; *av; ++av)
	{
		for (int i = 0; (*av)[i]; i++)
			(*av)[i] = toupper((*av)[i]);
		std::cout << *av;
	}
	std::cout << std::endl;
}