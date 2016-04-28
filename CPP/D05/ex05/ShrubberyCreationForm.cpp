/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 12:36:24 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/22 20:33:06 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	Form("SCF", 145, 137), _target(target){
		if (Form::getSGrade() > 150 || Form::getEGrade() > 150)
			throw ShrubberyCreationForm::GradeTooLowException();
		if (Form::getSGrade() <= 0 || Form::getEGrade() <= 0)
			throw ShrubberyCreationForm::GradeTooHighException();
	}


/// FUNCTIONS ///
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
		std::ofstream	ifs;
		std::string		file;

		file = this->_target + "_shrubbery";
		Form::execute(executor);
		ifs.open(file, std::ofstream::trunc);
		ifs << "                              $" << std::endl;
		ifs << "                              :$$" << std::endl;
		ifs << "                         seeee$$$Neeee" << std::endl;
		ifs << "                           R$$$F$$$$F" << std::endl;
		ifs << "                             $$$$$$" << std::endl;
		ifs << "                            @$$P*$$B" << std::endl;
		ifs << "                           z$#\"  $#$b" << std::endl;
		ifs << "                           \" d   'N \"" << std::endl;
		ifs << "                            @\"     ?r" << std::endl;
		ifs << "                          xF .       \"N" << std::endl;
		ifs << "                       .$> P54.R       `$" << std::endl;
		ifs << "                     $*   '*\"$$$  uoP***~" << std::endl;
		ifs << "                      #Noo \"?$N\"   #oL" << std::endl;
		ifs << "                         f       o$#$$\"e." << std::endl;
		ifs << "                        $  @b    hoR$$r ^\"$$b" << std::endl;
		ifs << "                     .M   ?B$E   *.B$$       .R" << std::endl;
		ifs << "                   .*     *\\ *.4*R         ..*" << std::endl;
		ifs << "                oo#     ooL    d#R.     P##~" << std::endl;
		ifs << "                $c    .\"\"P#$  @   P     k" << std::endl;
		ifs << "                  R$r ''?L$$  P  \"r     'N" << std::endl;
		ifs << "                    ^$ \"$$$` $.....JL     \"N." << std::endl;
		ifs << "                  .$\\           * P5\"LR      $.." << std::endl;
		ifs << "               ..* 4*R     xr    'PFN$$   .k    \"*****." << std::endl;
		ifs << "            od#\"   d#*.  \"*$$P~   \"?$*\" '#$$$\"       u\"" << std::endl;
		ifs << "         e\"\"      f   M   @F\"$  ec       x$\"$.     :\"" << std::endl;
		ifs << "         M        >  \"d       $$$$?$           .$$F`" << std::endl;
		ifs << "          \"P..  .$.....$L $$.4$$. \"   @#3$$   $E." << std::endl;
		ifs << "             '**..  *   R..$$ `R$*k.  fdM$$>     *.." << std::endl;
		ifs << "               J\"       *k$$$~  \"*$**o$o$$P        '*oo." << std::endl;
		ifs << "              P           #        \"$$$#*o          >  '####*oooo" << std::endl;
		ifs << "           .e\"            :e$$e.  F3  ^\"$P  :$$s :e@$ee        s\"" << std::endl;
		ifs << "         $P` M7>    $P$$k \"$\"?$3 @\"#N      CxN$$> .$$$       .P" << std::endl;
		ifs << "      M$~   J\\##   44N>$$  .d$.$d   @&      `$$$  F  .8..$$$*" << std::endl;
		ifs << "  .***     :   JM   *d$$*.$$.P  M  .P5     M          **." << std::endl;
		ifs << "  \"oo      J  .dP    ud$$od#   $oooooo$  oo$oo           ###ou" << std::endl;
		ifs << "     \"####$beeeee$.'$eeP#~        \"\"      $$$.    e$$$o       #heeee" << std::endl;
		ifs << "        :\"    \" z$r ^            o$N     '\"  \"   4$z>$$             \"\"\"#$$$" << std::endl;
		ifs << "       .~      F$4$B       r    F @#$.       ..   $8$$P M7                $" << std::endl;
		ifs << "     .*  $     8 $$B     .J$..  hP$$$F     .'PB$       J~##             .d~" << std::endl;
		ifs << "   .P  *$$$*    \"*\"       $$$    #**~      hdM$$>     <   JM.......*****" << std::endl;
		ifs << " .P     $#*k       .o#>  P\" \"k   ..         '$$P      d  .JP'h" << std::endl;
		ifs << "\"\"\"hr ^        xe\"\"  >          \"\"c           ee    @beeeee$.)" << std::endl;
		ifs << "      \"\"\"t$$$$F\"      M        $`   R          > \"$r     \"     \"c" << std::endl;
		ifs << "                              oooooooooo" << std::endl;
		ifs << "                              z        z" << std::endl;
		ifs << "                              z.,ze.$$$z" << std::endl;
		ifs.close();
}
