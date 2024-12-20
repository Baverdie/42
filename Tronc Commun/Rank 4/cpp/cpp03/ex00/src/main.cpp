/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:23:31 by bastienverdie     #+#    #+#             */
/*   Updated: 2024/12/20 19:40:58 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

int main() {
	ClapTrap clap1("Clappy");
	ClapTrap clap2("Trappy");

	std::cout << std::endl;

	clap1.attack("Target Dummy");
	clap1.takeDamage(3);
	clap1.beRepaired(5);

	std::cout << std::endl;
	
	for (int i = 0; i < 10; ++i)
		clap1.attack("Dummy");

	std::cout << std::endl;
	
	clap2.takeDamage(15);
	clap2.attack("Another Dummy");
	clap2.beRepaired(5);

	return 0;
}
