/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:06:41 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/24 15:06:41 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &original) {
	for (int i = 0; i < 4; i++)
		this->_materia[i] = original._materia[i];
}

MateriaSource &MateriaSource::operator=(MateriaSource const &original) {
	if (this != &original) {
		for (int i = 0; i < 4; i++) {
			if (this->_materia[i])
				delete this->_materia[i];
			this->_materia[i] = original._materia[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		delete this->_materia[i];
}

void MateriaSource::learnMateria(AMateria *materia) {
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i] == NULL) {
			this->_materia[i] = materia;
			std::cout << "Materia learned" << std::endl;
			return ;
		}
	}
	std::cout << "MateriaSource is full" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i] && this->_materia[i]->getType() == type)
			return (std::cout << this->_materia[i]->getType() << " Materia created" << std::endl, this->_materia[i]->clone());
	}
	std::cout << "Materia not found" << std::endl;
	return (0);
}

