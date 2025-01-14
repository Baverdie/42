/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:31:55 by bastienverdie     #+#    #+#             */
/*   Updated: 2025/01/10 15:05:48 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include "Animal.h"
#include "Brain.h"

class Cat : public Animal {
	private:
		Brain *brain;
		void makeSound() const;

	public:
		Cat();
		Cat(const Cat &other);
		Cat &operator=(Cat const &rhs);
		~Cat();

		Brain *getBrain() const;
};

#endif
