#include "CourbebNCurses.class.hpp"

#include <iostream>
#include <ncurses.h>

#include <iomanip>

#include "WindowNCurses.class.hpp"

#define HAUTEUR 10

CourbebNCurses::CourbebNCurses( WindowNCurses *win ): ACourbeb(), _win( win )
{
}


void	CourbebNCurses::displayRender( void )
{
	this->displayRender1();
	
}


static float moyenne(std::list<float> l) {
	std::list<float>::iterator	it = l.begin();
	std::list<float>::iterator	ite = l.end();
	float						res = 0;
	while (it != ite)
	{
		res += *it;
		++it;
	}
	return (res / l.size());
}
#define LARGE 40

void	CourbebNCurses::displayRender1( void )
{
	int oy = getcury( stdscr );
	int		x;
	x = moyenne(_data1) / (100.0f / (float)LARGE);
	mvprintw(oy, 0, "[");
	while (x)
	{
		char c;
		if (x > LARGE / 3 * 2)
			c = 1;
		else if (x > LARGE / 3)
			c = 2;
		else
			c = 3;
		attron(COLOR_PAIR(c));
		mvprintw(oy, --x + 1, "#");
		attroff(COLOR_PAIR(c));
	}
	mvprintw(oy++, LARGE, "] Core1");
	mvprintw(oy, 0, "[");
	x = moyenne(_data2) / 5;
	while (x)
	{
		char c;
		if (x > LARGE / 3 * 2)
			c = 1;
		else if (x > LARGE / 3)
			c = 2;
		else
			c = 3;
		attron(COLOR_PAIR(c));
		mvprintw(oy, --x + 1, "#");
		attroff(COLOR_PAIR(c));
	}
	mvprintw(oy++, LARGE, "] Core2");
	mvprintw(oy, 0, "[");
	x = moyenne(_data3) / 5;
	while (x)
	{
		char c;
		if (x > LARGE / 3 * 2)
			c = 1;
		else if (x > LARGE / 3)
			c = 2;
		else
			c = 3;
		attron(COLOR_PAIR(c));
		mvprintw(oy, --x + 1, "#");
		attroff(COLOR_PAIR(c));
	}
	mvprintw(oy++, LARGE, "] Core3");
	mvprintw(oy, 0, "[");
	x = moyenne(_data4) / 5;
	while (x)
	{
		char c;
		if (x > LARGE / 3 * 2)
			c = 1;
		else if (x > LARGE / 3)
			c = 2;
		else
			c = 3;
		attron(COLOR_PAIR(c));
		mvprintw(oy, --x + 1, "#");
		attroff(COLOR_PAIR(c));
	}
	mvprintw(oy++, LARGE, "] Core4");
	move(oy, 0);

	/*
	int h = 2 + oy + HAUTEUR;

	std::list< float >::iterator	it;
	it = this->_data1.begin();

//	int vmin = static_cast< int >(*it);

//	float max = *(std::max_element(it, ite));
	int w = 0;
	int val = static_cast< int >((HAUTEUR - ( *it / 10 )));	
	std::string	info = std::to_string(val);
	int g = val + oy;
	int c;
	if ( val >  HAUTEUR * 0.75)
		c = 1;
	else if ( val >  HAUTEUR * 0.25)
		c = 2;
	else
		c = 3;

	int a,b;

	a = oy;
	while ( a < val )
	{
		b = ox;

		while (b < 30)
		{
			mvprintw(b,a,"#");

			b++;
		}
		a++;
	}

	while ( g < h )
	{
		attron(COLOR_PAIR(c));
		mvprintw( g, w, "#" );
		attroff(COLOR_PAIR(c));
		g++;
	}

	mvprintw( oy + 1, ox + 1, info.c_str());
	int x, y, i;
	x = 30;
	int len = x;
	y = h;
	mvprintw(oy, ox, "+");
	mvprintw(y - 1, ox, "+");
	mvprintw(oy, x - 1, "+");
	mvprintw(y - 1, x - 1, "+");
	for (i = ox + 1; i < ( x - 1); i++) {
		mvprintw(oy, i, "-");
		mvprintw(h - 1, i, "-");
	}
	for (i = oy + 1; i < ( h - 1); i++) {
		mvprintw(i, ox, "|");
		mvprintw(i, len - 1, "|");
	}

	move(h , 0);
	*/
}
