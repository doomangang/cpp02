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

class   Fixed {
private:
	int                 _value;
	static const int    _fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed &other);
	~Fixed();
	Fixed&              operator=(const Fixed &other);
	int                 getRawBits( void ) const;
	void                setRawBits( int const raw );
};