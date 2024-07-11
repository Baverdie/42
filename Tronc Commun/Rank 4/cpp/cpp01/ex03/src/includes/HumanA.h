/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 03:22:49 by bastienverd       #+#    #+#             */
/*   Updated: 2024/07/11 03:22:50 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.h"

class HumanA
{
public:
	HumanA(const std::string &name, Weapon &wepon);

	void attack(void) const;

private:
	std::string _name;
	Weapon &_weapon;
};
