/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 00:07:22 by bastienverdie     #+#    #+#             */
/*   Updated: 2024/12/16 00:39:11 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
	private:
		int					_value;
		static const int	_fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &src);
		~Fixed();

		Fixed &operator=(const Fixed &rhs);

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
