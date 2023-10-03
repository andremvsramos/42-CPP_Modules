/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:55:33 by marvin            #+#    #+#             */
/*   Updated: 2023/10/03 16:55:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	c[8];
		int		size;
		int		index;

	public:
		PhoneBook();
		void	addContact();
		void	searchContact();
		void	displaySearch(int spacing);
		Contact	getContact(int index);
};

#endif
