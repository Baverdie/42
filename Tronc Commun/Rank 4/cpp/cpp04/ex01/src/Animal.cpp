/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:24:47 by bastienverdie     #+#    #+#             */
/*   Updated: 2025/01/10 14:32:54 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

Animal::Animal(void) : type("Animal") {
	std::cout << "Animal empty constructor called !" << std::endl;
}

Animal::Animal(const std::string &type) : type(type) {
	std::cout << "Animal constructor called !" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
	std::cout << "Animal copy constructor called !" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs) {
	if (this != &rhs)
		this ->type = rhs.getType();
	std::cout << "Animal assignment operator called !" << std::endl;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called !" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Animal makes a generic sound !" << std::endl;
}

const std::string &Animal::getType() const {
	return type;
}
