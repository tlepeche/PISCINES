
#ifndef COURBEBNCURSES_CLASS_HPP
# define COURBEBNCURSES_CLASS_HPP

# include "ACourbeb.class.hpp"
# include "WindowNCurses.class.hpp"
class CourbebNCurses: public ACourbeb
{

	public:

		CourbebNCurses( WindowNCurses *win );

		void	displayRender( void );
		void	displayRender1( void );
		void	displayRender2( void );
		void	displayRender3( void );
		void	displayRender4( void );

	private:

		WindowNCurses	*_win;

};

#endif
