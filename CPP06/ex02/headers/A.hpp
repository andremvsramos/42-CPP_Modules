/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:44:47 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/23 12:04:33 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_H
# define A_H

# include "Base.hpp"

# pragma once

class A : public Base {
    public:
        A();
        A(const A& original);
        A&    operator=(const A& original);
        virtual ~A();
};

#endif
