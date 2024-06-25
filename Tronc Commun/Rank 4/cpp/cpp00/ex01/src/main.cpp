/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:27:46 by basverdi          #+#    #+#             */
/*   Updated: 2024/06/25 17:35:42 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "includes/PhoneBook.h"

int	main() {
	std::string rep;

	std::cout << "Ecris un truc" << std::endl;
	getline(std::cin, rep); 
	std::cout << "Tu as ecris : " << rep << std::endl;
}
