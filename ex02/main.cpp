/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:28:04 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/11/23 17:28:07 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	//general test (from subject)
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	//manual test
	std::cout << "\nsimple manual test for overloaded operators\n";
	
	Fixed const copyB(b);
	Fixed c( Fixed( 5.05f ) / Fixed( 2 ) );
	Fixed const d( Fixed( 5.05f ) + Fixed( 2 ) );
	Fixed const e( Fixed( 5.05f ) - Fixed( 2 ) );

	std::cout << "a\t=" << a << std::endl;
	std::cout << "b\t=" << b << std::endl;
	std::cout << "c\t=" << c << std::endl;
	std::cout << "d\t=" << d << std::endl;
	std::cout << "e\t=" << e << std::endl;
	std::cout << "copyB\t=" << copyB << std::endl << std::endl;
	
	if (a < b)
		std::cout << "b is the larger one:\t" << "a=" << a << "\tb=" << b << std::endl;
	if (d >= c)
		std::cout << "c is the smaller one:\t" << "c=" << c << "\td=" << d  << std::endl;
	if (b == copyB)
		std::cout << "b and copyB are the same:\t" << "b=" << b << "\tcopyB=" << copyB << std::endl;
	if (d != e)
		std::cout << "d and e are not the same:\t" << "d=" << d << "\te=" << e << std::endl;

	std::cout << std::endl << "decrement a and c" << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << c-- << std::endl;
	std::cout << c << std::endl << std::endl;

	std::cout << "max a between c:" << Fixed::min( a, c ) << std::endl;
	std::cout << "min c between d:" << Fixed::min( c, d ) << std::endl;
	return 0;
}
