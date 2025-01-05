/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:34:06 by bastienverdie     #+#    #+#             */
/*   Updated: 2025/01/05 19:11:29 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.h"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &other);
		//operator !!!!!!
		ScavTrap(void);
		~ScavTrap(void);

		void attack(const std::string &target);
		void guardGate(void) const;
};
