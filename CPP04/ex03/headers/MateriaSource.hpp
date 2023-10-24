/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:01:13 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/24 15:01:13 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria	*_materia[4];

	public:
		MateriaSource();
		MateriaSource(MateriaSource const &original);
		MateriaSource &operator=(MateriaSource const &original);
		~MateriaSource();
		void	learnMateria(AMateria*);
		AMateria *createMateria(std::string const &type);
};

#endif
