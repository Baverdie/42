/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 03:23:10 by bastienverd       #+#    #+#             */
/*   Updated: 2024/12/05 13:09:46 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.h"

class HumanB
{
	private:
		std::string _name;
		Weapon *_weapon;

	public:
		HumanB(const std::string &name);
		void attack(void) const;
		void setWeapon(Weapon &weapon);
};
