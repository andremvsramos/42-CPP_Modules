/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:29:33 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/24 14:29:33 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		std::string	_type;

	public:
		Cure();
		Cure(Cure const &original);
		virtual ~Cure();
		Cure &operator=(Cure const &original);
		Cure* clone() const;
		void use(ICharacter& target);
};

#endif
