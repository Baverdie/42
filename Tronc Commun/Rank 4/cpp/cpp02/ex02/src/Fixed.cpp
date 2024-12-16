/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 00:42:09 by bastienverdie     #+#    #+#             */
/*   Updated: 2024/12/16 02:24:40 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int intValue) {
	_value = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue) {
	_value = roundf(floatValue * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &src) {
	*this = src;
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &rhs) {
	if (this != &rhs) {
		this->_value = rhs._value;
	}
	return *this;
}

int	Fixed::getRawBits(void) const {
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

bool Fixed::operator>(const Fixed &rhs) const {
	return this->_value > rhs._value;
}

bool Fixed::operator<(const Fixed &rhs) const {
	return this->_value < rhs._value;
}

bool Fixed::operator>=(const Fixed &rhs) const {
	return this->_value >= rhs._value;
}

bool Fixed::operator<=(const Fixed &rhs) const {
	return this->_value <= rhs._value;
}

bool Fixed::operator==(const Fixed &rhs) const {
	return this->_value == rhs._value;
}

bool Fixed::operator!=(const Fixed &rhs) const {
	return this->_value != rhs._value;
}

Fixed Fixed::operator+(const Fixed &rhs) const {
	Fixed result;
	result.setRawBits(this->_value + rhs._value);
	return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const {
	Fixed result;
	result.setRawBits(this->_value - rhs._value);
	return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const {
	Fixed result;
	result.setRawBits((this->_value * rhs._value) >> _fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const {
	Fixed result;
	result.setRawBits((this->_value << _fractionalBits) / rhs._value);
	return result;
}

Fixed &Fixed::operator++() {
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	this->_value++;
	return temp;
}

Fixed &Fixed::operator--() {
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->_value--;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}

float Fixed::toFloat(void) const {
	return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return _value >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
	out << value.toFloat();
	return out;
}
