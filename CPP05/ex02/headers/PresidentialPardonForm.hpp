#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# pragma once
# include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public virtual AForm
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& original);
        PresidentialPardonForm&    operator=(const PresidentialPardonForm& original);
        ~PresidentialPardonForm();

        PresidentialPardonForm(std::string target);

        void execute(const Bureaucrat& executor) const;
};

#endif
