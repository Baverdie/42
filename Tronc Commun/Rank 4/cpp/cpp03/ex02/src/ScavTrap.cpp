/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:34:23 by bastienverdie     #+#    #+#             */
/*   Updated: 2024/12/20 19:44:02 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"

ScavTrap::ScavTrap(const std::string &name) 
	: ClapTrap(name) {
	std::cout << "ScavTrap " << name << " constructor called !" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other)
	: ClapTrap(other) {
	*this = other;
	std::cout << "ScavTrap " << name << " constructor by copy called !" << std::endl;
}

ScavTrap::ScavTrap(void) {
	std::cout << "ScavTrap default constructor called !" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << name << " destructor called !" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (hitPoints <= 0 || energyPoints <= 0) {
		std::cout << "ScavTrap " << name << " has no energy or hit points left and can't attack !" << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage !" << std::endl;
}

void ScavTrap::guardGate(void) const {
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}
