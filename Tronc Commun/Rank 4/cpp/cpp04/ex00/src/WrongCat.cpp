/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:11:39 by bastienverdie     #+#    #+#             */
/*   Updated: 2025/01/04 18:16:57 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.h"

WrongCat::WrongCat() {
	this->type = "WrongCat";
	std::cout << "WrongCat constructor called !" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called !" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Meow (but wrong) !" << std::endl;
}
