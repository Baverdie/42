/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 03:23:42 by bastienverd       #+#    #+#             */
/*   Updated: 2024/07/11 03:24:03 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

Weapon::Weapon(const std::string &type) : _type(type) {}

void Weapon::setType(const std::string &type)
{
	_type = type;
}

std::string Weapon::getType(void) const
{
	return _type;
}