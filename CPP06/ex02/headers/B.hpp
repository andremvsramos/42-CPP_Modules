/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:44:38 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/23 12:04:28 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_H
# define B_H

# include "Base.hpp"

# pragma once

class B : public Base {
    public:
        B();
        B(const B& original);
        B&    operator=(const B& original);
        virtual ~B();
};

#endif
