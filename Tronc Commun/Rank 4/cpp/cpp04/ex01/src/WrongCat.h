/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:53:53 by bastienverdie     #+#    #+#             */
/*   Updated: 2025/01/10 14:28:00 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal {
	private:
		void makeSound() const;
	public:
		WrongCat();
		WrongCat(const WrongCat &other);
		WrongCat &operator=(WrongCat const &rhs);
		~WrongCat();
};

#endif
