/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:55:24 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/20 17:17:50 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie *zombieHorde(int N, std::string name) {

    Zombie *newZombies;

	if (N <= 0)
		return (NULL);
    newZombies = ::new Zombie[N];
    for (int i = 0; i < N; i++) {
        newZombies[i].setName(name);
    }
    return (newZombies);
}
