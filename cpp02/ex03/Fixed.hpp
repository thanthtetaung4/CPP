/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:25:55 by taung             #+#    #+#             */
/*   Updated: 2025/04/14 14:03:41 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
#define __FIXED_H__
#include <iostream>

class	Fixed {
	private:
		int					_rawBits;
		static const int	_fractional = 8;

	public:
		Fixed(void);
		Fixed(const Fixed& other);\
		Fixed(const int i);
		Fixed(const float f);
		float			toFloat( void ) const;
		int				toInt( void ) const;
		Fixed&			operator=(const Fixed& other);
		bool			operator>(const Fixed& other) const;
		bool			operator<(const Fixed& other) const;
		bool			operator>=(const Fixed& other) const;
		bool			operator<=(const Fixed& other) const;
		bool			operator==(const Fixed& other) const;
		bool			operator!=(const Fixed& other) const;
		Fixed			operator+(const Fixed& other) const;
		Fixed			operator-(const Fixed& other) const;
		Fixed			operator*(const Fixed& other) const;
		Fixed			operator/(const Fixed& other) const;
		Fixed&			operator++(void);
		Fixed			operator++(int);
		Fixed&			operator--(void);
		Fixed			operator--(int);
		static Fixed&	min(Fixed& p1, Fixed& p2);
		static Fixed&	min(const Fixed& p1,const Fixed& p2);
		static Fixed&	max(Fixed& p1, Fixed& p2);
		static Fixed&	max(const Fixed& p1,const Fixed& p2);
		friend std::ostream&	operator<<(std::ostream& os, const Fixed &fixed);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
