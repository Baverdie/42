/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:37:21 by bastienverdie     #+#    #+#             */
/*   Updated: 2025/01/04 18:23:19 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat constructor called !" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called !" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow Moew !" << std::endl;
}
