/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:23:31 by bastienverdie     #+#    #+#             */
/*   Updated: 2024/12/20 19:26:33 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"

int main() {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~" << std::endl;	
	
	ScavTrap scav1("Scavy");
	ScavTrap scav2("Trapster");
	
	std::cout << std::endl;
	
	scav1.attack("Target Dummy");
	scav1.guardGate();
	
	std::cout << std::endl;
	
	scav1.takeDamage(50);
	scav1.beRepaired(30);
	
	std::cout << std::endl;
	
	for (int i = 0; i < 52; ++i)
		scav2.attack("Energy Dummy");
	return 0;
}
