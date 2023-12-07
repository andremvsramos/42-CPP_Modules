/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:45:31 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/23 12:04:44 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_H
# define C_H

# include "Base.hpp"

# pragma once

class C : public Base {
    public:
        C();
        C(const C& original);
        C&    operator=(const C& original);
        virtual ~C();
};

#endif
