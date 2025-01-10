/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:31:55 by bastienverdie     #+#    #+#             */
/*   Updated: 2025/01/10 14:09:10 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal {
	private:
		void makeSound() const;
	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(Dog const &rhs);
		~Dog();
};

#endif
