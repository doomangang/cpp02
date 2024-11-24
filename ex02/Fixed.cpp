/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:20:27 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/11/23 17:40:28 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	//std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other)
{
	//std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed::Fixed(const int intNum)
{
	//std::cout << "Int constructor called\n";
	_value = intNum << _fractionalBits;
}

Fixed::Fixed(const float floatNum)
{
	//std::cout << "Float constructor called\n";
	_value = roundf(floatNum * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called\n";
}

Fixed& Fixed::operator=(const Fixed &other)
{
	//std::cout << "Copy assignment operator called\n";
	_value = (int)(other.toFloat() * (1 << _fractionalBits));
	return *this;
}

int Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called\n";
	return _value;
}

void Fixed::setRawBits( int const raw )
{
	//std::cout << "setRawBits member function called\n";
	_value = raw;
}

float Fixed::toFloat() const
{
	 return ((float)_value / (1 << _fractionalBits));
}

int Fixed::toInt() const
{
	return (_value >> _fractionalBits);
}

std::ostream& operator <<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

bool                Fixed::operator>(const Fixed &other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool                Fixed::operator<(const Fixed &other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool                Fixed::operator>=(const Fixed &other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool                Fixed::operator<=(const Fixed &other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool                Fixed::operator==(const Fixed &other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool                Fixed::operator!=(const Fixed &other) const
{
	return (this->getRawBits() != other.getRawBits());
}

Fixed              Fixed::operator+(const Fixed &other) const
{
	Fixed   result(this->toFloat() + other.toFloat());
	return (result);
}

Fixed              Fixed::operator-(const Fixed &other) const
{
	Fixed   result(this->toFloat() + other.toFloat());
	return (result);
}

Fixed              Fixed::operator*(const Fixed &other) const
{
	Fixed   result(this->toFloat() * other.toFloat());
	return (result);
}

Fixed              Fixed::operator/(const Fixed &other) const
{
	Fixed   result(this->toFloat() / other.toFloat());
	return (result);
}

Fixed&              Fixed::operator++(void)
{
	_value++;
	return (*this);
}

const Fixed         Fixed::operator++(int)
{
	const Fixed copy = Fixed(*this);
	_value++;
	return (copy);
}

Fixed&              Fixed::operator--(void)
{
	_value--;
	return (*this);
}

const Fixed         Fixed::operator--(int)
{
	const Fixed copy = Fixed(*this);
	_value--;
	return (copy);
}

Fixed&       Fixed::min(Fixed& ref1, Fixed& ref2)
{
	if (ref1 < ref2)
		return ref1;
	return ref2;
}
const Fixed& Fixed::min(Fixed const& ref1, Fixed const& ref2)
{
	if (ref1 < ref2)
		return ref1;
	return ref2;
}

Fixed&       Fixed::max(Fixed& ref1, Fixed& ref2)
{
	if (ref1 > ref2)
		return ref1;
	return ref2;
}

const Fixed& Fixed::max(Fixed const& ref1, Fixed const& ref2)
{
	if (ref1 > ref2)
		return ref1;
	return ref2;
}