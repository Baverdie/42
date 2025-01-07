/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:17:29 by bastienverdie     #+#    #+#             */
/*   Updated: 2025/01/08 00:48:22 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"

FragTrap::FragTrap() {
	std::cout << "FragTrap default constructor called !" << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

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


FragTrap &FragTrap::operator=(const FragTrap &rhs) {
    ClapTrap::operator=(rhs);
    std::cout << "FragTrap copy assignment operator called !" << std::endl;
    return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << name << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FrageTrap " << name << " high fives request" << std::endl;
}
