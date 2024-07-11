/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 02:28:52 by bastienverd       #+#    #+#             */
/*   Updated: 2024/07/11 02:37:19 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once

#include	<string>
#include	<iostream>

class	Zombie {
	private:
		std::string _name;

	public:
		Zombie(const std::string& name);

	void announce(void) const;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);