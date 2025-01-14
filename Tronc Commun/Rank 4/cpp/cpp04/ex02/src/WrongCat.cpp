/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:11:39 by bastienverdie     #+#    #+#             */
/*   Updated: 2025/01/10 14:35:38 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.h"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat empty constructor called !" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal("WrongCat") {
	if (this != &other)
		*this = other;
	std::cout << "WrongCat copy constructor called !" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs) {
	if (this != &rhs)
		this->type = rhs.getType();
	std::cout << "Animal assignment operator called !" << std::endl;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called !" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Meow (but wrong) !" << std::endl;
}
