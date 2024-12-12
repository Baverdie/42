/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 03:23:42 by bastienverd       #+#    #+#             */
/*   Updated: 2024/12/12 17:23:01 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

Weapon::Weapon(const std::string &type) : _type(type) {}

void Weapon::setType(const std::string &type)
{
	_type = type;
}

const std::string &Weapon::getType(void) const
{
	return this->_type;
}
