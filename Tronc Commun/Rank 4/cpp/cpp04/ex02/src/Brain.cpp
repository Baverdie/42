/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:46:01 by bastienverdie     #+#    #+#             */
/*   Updated: 2025/01/10 14:58:13 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.h"

Brain::Brain() {
	std::cout << "Brain empty constructor called !" << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain copy constructor called !" << std::endl;
	*this = other;
}

Brain &Brain::operator=(Brain const &rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 100; ++i) {
			ideas[i] = rhs.getIdea(i);
		}
		std::cout << "Brain copy assignement operator called !" << std::endl;
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called !" << std::endl;
}

void Brain::setIdea(int index, const std::string &idea) {
	if (index >= 0 && index < 100) {
		ideas[index] = idea;
	}
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100) {
		return ideas[index];
	}
	return "";
}
