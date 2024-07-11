/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 03:23:02 by bastienverd       #+#    #+#             */
/*   Updated: 2024/07/11 03:30:21 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Weapon
{
public:
	Weapon(const std::string &type);

	void setType(const std::string &type);
	std::string getType(void) const;

private:
	std::string _type;
};
