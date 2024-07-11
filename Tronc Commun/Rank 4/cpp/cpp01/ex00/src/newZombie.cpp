/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 02:42:19 by bastienverd       #+#    #+#             */
/*   Updated: 2024/07/11 02:42:24 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie *newZombie(std::string name)
{
	Zombie *newZombie;

	newZombie = ::new Zombie(name);
	return (newZombie);
}