/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:15:33 by bastienverd       #+#    #+#             */
/*   Updated: 2025/02/03 15:15:34 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;
		bob.incrementGrade();
		std::cout << bob << std::endl;
		bob.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception capturée: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat alice("Alice", 149);
		std::cout << alice << std::endl;
		alice.decrementGrade();
		std::cout << alice << std::endl;
		alice.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception capturée: " << e.what() << std::endl;
	}

	return 0;
}