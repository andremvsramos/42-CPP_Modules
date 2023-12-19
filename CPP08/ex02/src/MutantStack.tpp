/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:30:24 by andvieir          #+#    #+#             */
/*   Updated: 2023/12/19 18:30:24 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

/* ===================== Orthodox Canonical Form ===================== */

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> & original) {
	*this = original;
}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(const MutantStack<T> & original) {
	std::stack<T>::operator=(this, original);
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {}

/* ===================== Iterator Functions ===================== */

template <typename T>
typename MutantStack<T>::it MutantStack<T>::begin() {
	return (this->c.begin());
}

template  <typename T>
typename MutantStack<T>::it MutantStack<T>::end() {
	return (this->c.end());
}

#endif
