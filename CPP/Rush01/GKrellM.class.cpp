#include "GKrellM.class.hpp"
#include "SessionModule.class.hpp"
#include "OSinfoModule.class.hpp"
#include "CpuModule.class.hpp"
#include "RamModule.class.hpp"
#include "NetworkModule.class.hpp"
#include "DateModule.class.hpp"
#include "WindowNCurses.class.hpp"
#include "WindowSfml.class.hpp"
#include <ncurses.h>


GKrellM::GKrellM(void) {}

void		GKrellM::run(void) {
	if (_displayType == "ncurses") { // NCURSES
		clear();
		if (getch() == 27)
		{
			this->~GKrellM();
		}
		move( 0, 0);
	}
	else { // SFML
		_windowSfml->clear();
		sf::Event	event;

		while (_windowSfml->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				exit(0);
		}
	
	}
	std::list<IMonitorModule*>::iterator	it = _modules.begin();
	std::list<IMonitorModule*>::iterator	ite = _modules.end();

	try {
		while (ite-- != it)
		{
			(*ite)->acquireData();
			(*ite)->displayRender();
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	if (_displayType == "ncurses") { // NCURSES
		refresh();
	}
	else { // SFML
		_windowSfml->display();
	}
}

GKrellM::GKrellM(int ac, char **av) {
	// add all MonitorModule to a list
	AWindow		*win;

	if (av[0][0] == '\127')
		win = NULL;
	if (ac > 2)
		_displayType = "ncurses";
	if (_displayType == "ncurses") { // NCURSES
		this->startCurses();
		win = new WindowNCurses(0, 0, 10, 10);
	}
	else
	{ // SFML
		_windowSfml = new sf::RenderWindow(sf::VideoMode(900, 380), "ft_gkrellm");
		win = new WindowSfml(0, 0, 900, 380, _windowSfml);
	}
	// Step 1
	_modules.push_front(new SessionModule(win));
	_modules.push_front(new OSinfoModule(win));
	_modules.push_front(new DateModule(win));
	// Step 2
	_modules.push_front(new CpuModule(win));
	_modules.push_front(new RamModule(win));
	// Step 3
//	_modules.push_front(new OSinfoModule(win));
	_modules.push_front(new NetworkModule(win));
///	_modules.push_front(new NetworkModule(win));
	// Step 4
	// _modules.push_front(new ZazModule(win));



}

GKrellM::~GKrellM(void) {
	// rm all MonitorModule to a list
	if (_displayType == "ncurses") // NCURSES
	{
		this->endCurses();

	}
	else // SFML
	{

	}
	exit(1);
}

GKrellM::GKrellM(GKrellM const & rhs) {
	*this = rhs;
}

GKrellM	&GKrellM::operator=(GKrellM const &rhs) {
	_windowSfml = rhs._windowSfml;
	return (*this);
}

void	GKrellM::startCurses( void )
{
	initscr();
	cbreak();
	noecho();
	nodelay( stdscr, true );
	curs_set( false );
	intrflush( stdscr, false  );
	keypad( stdscr, true );
	start_color();
	init_pair( 1, COLOR_RED, COLOR_BLACK );
	init_pair( 2, COLOR_YELLOW, COLOR_BLACK);
	init_pair( 3, COLOR_GREEN, COLOR_BLACK);
	return;
}

void	GKrellM::endCurses( void )
{
	if ( !isendwin() )
		endwin();
	return;
}
