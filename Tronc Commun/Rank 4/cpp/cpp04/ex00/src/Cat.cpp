/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:37:21 by bastienverdie     #+#    #+#             */
/*   Updated: 2025/01/10 14:34:12 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat constructor called !" << std::endl;
}

Cat::Cat(const Cat &other) : Animal("Cat") {
  if (this != &other)
    *this = other;
  std::cout << "Cat constructor by copy called !" << std::endl;
}

Cat &Cat::operator=(Cat const &rhs) {
	if (this != &rhs)
		this->type = rhs.getType();
	std::cout << "Cat assignment operator called !" << std::endl;
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called !" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow Moew !" << std::endl;
}
