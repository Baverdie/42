/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:21:14 by bastienverdie     #+#    #+#             */
/*   Updated: 2025/01/14 16:43:14 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

int main() {
	std::cout << "=== Test tableau ===" << std::endl; 
	const Animal *animals[4];

	for (int i = 0; i < 2; ++i)
		animals[i] = new Dog();

	for (int i = 2; i < 4; ++i)
		animals[i] = new Cat();

	for (int i = 0; i < 4; ++i)
		animals[i]->makeSound();

	for (int i = 0; i < 4; ++i)
		delete animals[i];

	std::cout << "=== Test copie ===" << std::endl;
	Dog dog1;
	dog1.getBrain()->setIdea(0, "Chasing cats");
	Dog dog2 = dog1;

	std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;

	dog2.getBrain()->setIdea(0, "Playing fetch");
	std::cout << "Dog1 idea after change: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 idea after change: " << dog2.getBrain()->getIdea(0) << std::endl;

	return 0;
}
