/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 02:28:52 by bastienverd       #+#    #+#             */
/*   Updated: 2024/07/11 02:49:20 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once

#include	<string>
#include	<iostream>

class	Zombie {
	private:
		std::string _name;

	public:
		Zombie(void);
		Zombie(const std::string& name);

		void setName(const std::string &name);
		void announce(void) const;
};

Zombie *zombieHorde(int N, std::string name);