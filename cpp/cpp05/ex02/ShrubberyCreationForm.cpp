#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(string target) : Form("ShrubberyCreationForm", 145, 137), target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& a) : Form("ShrubberyCreationForm", 145, 137), target(a.target) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}
ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& a)
{
	target = a.target;
	return *this;
}

void ShrubberyCreationForm::_execute() const
{
	std::ofstream f((target + "_shrubbery").c_str());
	if (f.is_open())
	{
		f << "          *" << endl;
		f << "         *o*" << endl;
		f << "        *v*o*" << endl;
		f << "       ***o***" << endl;
		f << "      **o**v*o*" << endl;
		f << "     **v**o**o**" << endl;
		f << "    **o**v***v*o*" << endl;
		f << "   *****v*o**o****" << endl;
		f << "  **v**o*****o**v**" << endl;
		f << " ******o*****v**o***" << endl;
		f << "****o***v**o***o***v*" << endl;
		f << "     ____|_|____" << endl;
		f << "     \\_________/" << endl;
		f.close();
	}
}
