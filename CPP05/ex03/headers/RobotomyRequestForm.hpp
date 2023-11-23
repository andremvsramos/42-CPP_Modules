#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# pragma once
# include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public virtual AForm
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& original);
        RobotomyRequestForm&    operator=(const RobotomyRequestForm& original);
        ~RobotomyRequestForm();

        RobotomyRequestForm(std::string target);

        void execute(const Bureaucrat& executor) const;
};

#endif
