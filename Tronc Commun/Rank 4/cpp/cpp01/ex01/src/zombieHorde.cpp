/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 02:45:04 by bastienverd       #+#    #+#             */
/*   Updated: 2024/07/11 02:56:54 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];

	if (N <= 0)
		return (NULL);
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}