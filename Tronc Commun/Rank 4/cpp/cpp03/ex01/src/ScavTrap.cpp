/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:34:23 by bastienverdie     #+#    #+#             */
/*   Updated: 2025/01/08 00:07:47 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"
#include "ClapTrap.h"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap default constructor called !" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
}

ScavTrap::ScavTrap(const std::string &name) 
	: ClapTrap(name) {
	std::cout << "ScavTrap " << name << " constructor called !" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
}

ScavTrap::ScavTrap(const ScavTrap &other)
	: ClapTrap(other) {
	*this = other;
	std::cout << "ScavTrap " << name << " constructor by copy called !" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
    ClapTrap::operator=(rhs);
    std::cout << "ScavTrap copy assignment operator called!" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() {
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

void ScavTrap::guardGate() const {
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}
