/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:37:21 by bastienverdie     #+#    #+#             */
/*   Updated: 2025/01/10 15:22:21 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.h"

Dog::Dog() : Animal("Dog"), brain(new Brain()) {
	std::cout << "Dog constructor called !" << std::endl;
}

Dog::Dog(const Dog &other) : Animal("Dog"), brain(new Brain(*other.brain)) {
	if (this != &other)
		*this = other;
	std::cout << "Dog constructor by copy called !" << std::endl;
}

Dog &Dog::operator=(Dog const &rhs) {
  if (this != &rhs) {
    this->type = rhs.getType();
	this->brain->operator=(*rhs.brain);
  }
  std::cout << "Dog assignment operator called !" << std::endl;
  return (*this);
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog destructor called !" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof Woof !" << std::endl;
}

Brain *Dog::getBrain() const {
	return brain;
}
