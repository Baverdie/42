/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:37:21 by bastienverdie     #+#    #+#             */
/*   Updated: 2025/01/04 18:45:56 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.h"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog constructor called !" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called !" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof Woof !" << std::endl;
}
