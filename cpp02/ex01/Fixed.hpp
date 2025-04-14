/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:25:55 by taung             #+#    #+#             */
/*   Updated: 2025/04/09 18:59:11 by taung            ###   ########.fr       */
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
		friend std::ostream&	operator<<(std::ostream& os, const Fixed &fixed);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
