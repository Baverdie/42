/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:17:29 by bastienverdie     #+#    #+#             */
/*   Updated: 2024/12/20 19:44:21 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"

FragTrap::FragTrap(const std::string &name)
	: ClapTrap(name) {
	std::cout << "FragTrap " << name << "constructor called ! " << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other)
	: ClapTrap(other) {
	*this = other;
	std::cout << "FragTrap " << name << " constructor by copy called !" << std::endl;
}

FragTrap::FragTrap(void) {
	std::cout << "FragTrap default constructor called" << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 20;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << name << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FrageTrap " << name << " high fives request" << std::endl;
}
