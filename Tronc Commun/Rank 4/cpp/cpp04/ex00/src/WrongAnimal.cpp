/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:24:47 by bastienverdie     #+#    #+#             */
/*   Updated: 2025/01/04 17:53:14 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.h"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "WrongAnimal constructor called !" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called !" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal makes a generic sound !" << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->type;
}
