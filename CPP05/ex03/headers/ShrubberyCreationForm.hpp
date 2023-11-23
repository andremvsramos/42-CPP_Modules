/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:26:18 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/13 11:13:46 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# pragma once

# include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public virtual AForm
{

    private:
        std::string _outfile;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& original);
        ShrubberyCreationForm&    operator=(const ShrubberyCreationForm& original);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm(std::string target);
        std::string getOutfile() const;
        void execute(const Bureaucrat& executor) const;
};

#endif
