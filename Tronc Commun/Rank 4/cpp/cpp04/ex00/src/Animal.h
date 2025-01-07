/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:19:07 by bastienverdie     #+#    #+#             */
/*   Updated: 2025/01/04 18:49:43 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal {
	protected:
		std::string type;
	
	public:
		Animal();
		Animal(const std::string &type);
		Animal(const Animal &other);
		Animal &operator=(const Animal &rhs);
		virtual ~Animal();

		virtual void makeSound() const;
		std::string getType() const;
};

#endif
