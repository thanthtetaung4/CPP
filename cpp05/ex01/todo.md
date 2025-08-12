


- The grades of the Form follow the same rules as those of the Bureaucrat. Thus, the
	qfollowing exceptions will be thrown if a form’s grade is out of bounds:
	qForm::GradeTooHighException and Form::GradeTooLowException.
	qAs before, write getters for all attributes and overload the insertion («) operator to print all the form’s information.

Also, add a beSigned() member function to the Form that takes a Bureaucrat as a
parameter. It changes the form’s status to signed if the bureaucrat’s grade is high enough
(greater than or equal to the required one). Remember, grade 1 is higher than grade 2.
If the grade is too low, throw a Form::GradeTooLowException.
Then, modify the signForm() member function in the Bureaucrat class. This func-
tion must call Form::beSigned() to attempt to sign the form. If the form is signed
successfully, it will print something like:
<bureaucrat> signed <form>
Otherwise, it will print something like:
<bureaucrat> couldn’t sign <form> because <reason>
