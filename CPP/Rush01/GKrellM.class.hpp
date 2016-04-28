
#ifndef GKRELLM_CLASS_HPP
#define GKRELLM_CLASS_HPP

#include <list>
#include "IMonitorModule.class.hpp"
#include <SFML/Graphics.hpp>

class	GKrellM
{
	private:
		GKrellM(void);
	protected:
		std::list<IMonitorModule*>	_modules;
		sf::RenderWindow			*_windowSfml;
		std::string					_displayType;
	public:
		GKrellM(int ac, char **av);
		~GKrellM(void);
		GKrellM(GKrellM const & rhs);
		GKrellM	&operator=(GKrellM const &rhs);

		void	startCurses( void );
		void	endCurses( void );

		void		run(void);
};

#endif
