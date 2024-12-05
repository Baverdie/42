/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 03:22:49 by bastienverd       #+#    #+#             */
/*   Updated: 2024/12/05 13:08:57 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.h"

class HumanA
{
	private:
		std::string _name;
		Weapon &_weapon;

	public:
		HumanA(const std::string &name, Weapon &wepon);
		void attack(void) const;
};
