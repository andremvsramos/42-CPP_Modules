/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:20:51 by andvieir          #+#    #+#             */
/*   Updated: 2023/12/19 18:20:51 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {

	public:
		MutantStack();
		MutantStack(const MutantStack & original);
		MutantStack & operator=(const MutantStack & original);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator it;

		it begin();
		it end();
};

# include "../src/MutantStack.tpp"

#endif
