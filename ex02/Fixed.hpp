/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:27:44 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/11/23 17:27:48 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class   Fixed {
private:
	int                 _value;
	static const int    _fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed(const int intNum);
	Fixed(const float floatNum);
	~Fixed();

	int                 getRawBits( void ) const;
	void                setRawBits( int const raw );
	float               toFloat( void ) const;
	int                 toInt( void ) const;
	Fixed&              operator=(const Fixed &other);
	bool                operator>(const Fixed &other) const;
	bool                operator<(const Fixed &other) const;
	bool                operator>=(const Fixed &other) const;
	bool                operator<=(const Fixed &other) const;
	bool                operator==(const Fixed &other) const;
	bool                operator!=(const Fixed &other) const;
	Fixed               operator+(const Fixed &other) const;
	Fixed               operator-(const Fixed &other) const;
	Fixed               operator*(const Fixed &other) const;
	Fixed               operator/(const Fixed &other) const;
	Fixed&              operator++(void);
	const Fixed         operator++(int);
	Fixed&              operator--(void);
	const Fixed         operator--(int);
	static Fixed&       min(Fixed& ref1, Fixed& ref2);
	static const Fixed& min(Fixed const& ref1, Fixed const& ref2);
	static Fixed&       max(Fixed& ref1, Fixed& ref2);
	static const Fixed& max(Fixed const& ref1, Fixed const& ref2);
};

std::ostream& operator  <<(std::ostream &out, const Fixed &fixed);