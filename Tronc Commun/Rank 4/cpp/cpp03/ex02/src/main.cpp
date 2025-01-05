/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:23:31 by bastienverdie     #+#    #+#             */
/*   Updated: 2025/01/05 19:13:50 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"
#include "ScavTrap.h"

int main() {
	FragTrap frag1("Fragy");
	FragTrap frag2("Trappy");
	
	std::cout << std::endl;

	frag1.attack("Target Dummy");
	frag1.highFivesGuys();

	std::cout << std::endl;

	frag1.takeDamage(70);
	frag1.beRepaired(50);

	std::cout << std::endl;

	for (int i = 0; i < 102; ++i)
		frag2.attack("Energy Dummy");

	return 0;
}
