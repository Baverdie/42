/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 03:23:10 by bastienverd       #+#    #+#             */
/*   Updated: 2024/07/11 03:23:17 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.h"

class HumanB
{
public:
	HumanB(const std::string &name);

	void attack(void) const;
	void setWeapon(Weapon &weapon);

private:
	std::string _name;
	Weapon *_weapon;
};