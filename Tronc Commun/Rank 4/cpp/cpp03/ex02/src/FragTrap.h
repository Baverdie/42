/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:52:39 by bastienverdie     #+#    #+#             */
/*   Updated: 2025/01/08 00:35:19 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.h"

class FragTrap : public ClapTrap {
  public:
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &rhs);
    FragTrap(void);
    ~FragTrap(void);

    void highFivesGuys(void);
};
