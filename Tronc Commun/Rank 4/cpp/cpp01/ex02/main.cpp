/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 03:11:05 by bastienverd       #+#    #+#             */
/*   Updated: 2024/07/11 03:14:29 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	const std::string	string = "HI THIS IS BRAIN";
	const std::string *stringPTR = &string;
	const std::string &stringREF = string;

	std::cout << "The memory address of the string variable : " << &string << std::endl;
	std::cout << "The memory address held by stringPtr      : " << stringPTR << std::endl;
	std::cout << "The memory address held by stringRef      : " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "The value of the string variable  : " << string << std::endl;
	std::cout << "The value pointed to by stringPtr : " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringRef : " << stringREF << std::endl;
	return (0);
}