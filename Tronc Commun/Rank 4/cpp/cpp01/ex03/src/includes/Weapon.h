/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 03:23:02 by bastienverd       #+#    #+#             */
/*   Updated: 2024/12/12 17:23:11 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string _type;

	public:
		Weapon(const std::string &type);
		void setType(const std::string &type);
		const std::string &getType(void) const;
};
