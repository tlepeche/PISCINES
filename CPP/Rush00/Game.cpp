/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 14:07:58 by sduprey           #+#    #+#             */
/*   Updated: 2015/06/21 11:43:44 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game( void ) : _go(false), _timer(0), _life(3), _bomb(3)
{
	this->_curses_started = false;
	this->_p = new Player;
	this->_men = new MenuTop;
	this->_top = new Bckgd(364, 4);
	this->_bot = new Bckgd(364, 7);
	this->_sq = new Squad;
	return;
}

Game::~Game( void )
{
	return;
}

Game::Game( Game const &rhs )
{
	(void)rhs;
	return;
}

Game	&Game::operator=( Game const &rhs )
{
	(void)rhs;
	return *this;
}

void	Game::endCurses( void )
{
	if (this->_curses_started && !isendwin())
		endwin();
}

void	Game::startCurses( void )
{
	if (this->_curses_started)
		refresh();
	else
	{
		initscr();
		cbreak();
		noecho();
		nodelay(stdscr, true);
		curs_set(false);
		intrflush(stdscr, false);
		keypad(stdscr, true);
		timeout(0);
		_curses_started = true;
		start_color();
		init_pair(1, COLOR_RED, COLOR_BLACK);
		init_pair(2, COLOR_GREEN, COLOR_BLACK);
		init_pair(3, COLOR_WHITE, COLOR_WHITE);
		init_pair(4, COLOR_YELLOW, COLOR_BLACK);
		init_pair(5, COLOR_WHITE, COLOR_BLUE);
		init_pair(6, COLOR_CYAN, COLOR_BLACK);
	}
}

/// GETTERS ///
Player	*Game::getPlayer( void ) const { return this->_p; }
int		Game::getLife(void) const {return this->_life; }
int		Game::getBomb(void) const {return this->_bomb; }

/// SETTERS ///
void	Game::setLife(int val) {
	this->_life += val;
	if (this->_life < 0)
		this->_life = 0;
	if (this->_life > 4)
		this->_life = 4;
}

void	Game::setBomb(int val) {
	this->_bomb += val;
	if (this->_bomb < 0)
		this->_bomb = 0;
	if (this->_bomb > 4)
		this->_bomb = 4;
}

/// FUNCTIONS ///
void	Game::mainLoop(void) {

	int		old_tt = 0;
	int		ch = 0;
	int		t = 0;
	int		a;
	int		x;
	int		y;
	bool	pause = true;
	int		t_saved = 0;
	MenuStart mst;
	bool	menu = true;


	this->startCurses();
	WINDOW *win = newwin(364 -1, 84 - 1, 0, 0);
	(void)win;

	while(42)
	{
		getmaxyx(stdscr, y, x);
		old_tt = this->_timer;
		this->_timer = t / 50000;
		ch = getch();
		if (ch == 'q')
			break;
		if (y == 84 && x == 364)
		{
			if (menu)
			{
				menu = false;
				if (mst.mainLoop() == 0)
					return ;
				nodelay(stdscr, true);
			}
			if (pause == false)
				t = t_saved;
			t_saved = t;
			pause = true;
			if (this->_go == false)
				this->_p->playerMove( ch );
			else
			{
				if (this->_life > 0)
				{
					this->displayMessage(2);
					if (ch == 'r')
					{
						this->_go = false;
						nodelay(stdscr, true);
						this->setLife(-1);
						this->_p->display();
						this->_p->setPos( 45, 10);
					}
				}
				else
				{
					menu = true;
					t = 0;
					this->displayMessage( 1 );
					this->_life = 3;
					this->_bomb = 3;
					this->_p->setPos(45, 10);
					this->_p->display();
					this->_go = false;
					Squad::_score = 0;
					a = 0;
					while (a < 15)
					{
						if (this->_sq->getUnit(a))
							this->_sq->destroy(this->_sq->getUnit(a), false);
						a++;
					}
				}
			}
			if (ch == 'b')
			{
				if (this->_bomb > 0)
				{
					this->_sq->useBomb();
					this->_bomb--;
				}
			}
			if (this->_timer == old_tt + 1)
			{
				if (std::rand() % 10 == 0)
					this->enemySpawn(this->_timer / 30);
				clear();
				this->_p->display();
				this->displayMenu();
				this->displayBckgd();
				this->getPlayer()->getWeapon()->checkEnemy( *this->_sq );
				if (this->_sq->checkPlayer( this->_p ) == 1)
					this->_go = true;
				this->_p->getWeapon()->display();
				a = 0;
				while (a < 15)
				{
					if (this->_sq->getUnit(a) != NULL)
					{
						this->_sq->getUnit(a)->display();
						this->_sq->getUnit(a)->entMove();
						if (this->_sq->getUnit(a)->getX() < 2)
							this->_sq->destroy(this->_sq->getUnit(a), false);
						if (this->_sq->getUnit(a) && this->_sq->getUnit(a)->getBoss() == true)
						{
							this->_sq->getUnit(a)->shoot();
							if (this->_sq->getUnit(a)->getWeap()->checkHit(this->_p) == 1)
								this->_go = true;
						}
					}
					a++;
				}
			}
			if (this->_go == true)
			{
				this->_p->playerExplodes();
				nodelay(stdscr, false);
			}
		}
		else
		{
			pause = false;
			if (this->_timer == old_tt + 1)
			{
				clear();
				mvprintw(y / 2 + 1, x / 2 - 10, "You must play in full screen");
				mvprintw(y / 2, x / 2 - 2, "Game Paused");
				refresh();
			}
		}
		if (this->_timer == old_tt + 1)
			refresh();
		t++;
	}
}

void	Game::displayMenu( void ) const {
	this->_men->display(this->_timer, this->_life, this->_bomb);
}

void	Game::displayMessage( int n )
{
	int w = (WIDTH / 2) - 40;
	int	h = (HEIGHT / 2) - 10;
	if (n == 1)
	{	attron(COLOR_PAIR(1));
		mvprintw(h, w, "     ________   __  _______  ____ _   _________");
		mvprintw(h + 1, w, "    / ___/ _ | /  |/  / __/ / __ \\ | / / __/ _ \\");
		mvprintw(h + 2, w, "   / (_ / __ |/ /|_/ / _/  / /_/ / |/ / _// , _/");
		mvprintw(h + 3, w, "   \\___/_/ |_/_/  /_/___/  \\____/|___/___/_/|_|");
		mvprintw(h + 5, w + 16, "Press Q to quit");
		attroff(COLOR_PAIR(1));
	}
	else
	{
		attron(COLOR_PAIR(2));
		mvprintw(h, w, "     _________  _  _____________  ____  ______");
		mvprintw(h + 1, w, "    / ___/ __ \\/ |/ /_  __/  _/ |/ / / / / __/");
		mvprintw(h + 2, w, "   / /__/ /_/ /    / / / _/ //    / /_/ / _/  ");
		mvprintw(h + 3, w, "   \\___/\\____/_/|_/ /_/ /___/_/|_/\\____/___/");
		mvprintw(h + 5, w + 16, "Press R to retry");
		attroff(COLOR_PAIR(2));
	}
}

void	Game::displayBckgd(void) {
	int	i = 0;
	int    j;

	while (i < this->_top->getLen())
	{
		j = 0;
		while (j <= this->_top->getTab(i))
		{
			move(j + 5, i);
			if (this->getPlayer()->playerUpdate(j + 5, i))
				this->_go = true;
			attron(COLOR_PAIR(3));
			printw("#");
			attroff(COLOR_PAIR(3));
			j++;
		}
		j = 0;
		while (j <= this->_bot->getTab(i))
		{
			move(84 - j - 1, i);
			if (this->getPlayer()->playerUpdate(84 - j - 1, i))
				this->_go = true;
			attron(COLOR_PAIR(3));
			printw("#");
			attroff(COLOR_PAIR(3));
			j++;
		}
		i++;
	}
	this->_top->refresh();
	this->_bot->refresh();
}

void	Game::enemySpawn(int time) {
	int		choice;
	int		y;

	y = (std::rand() % 60) + 10;

	if (time > 10 && Squad::_score > 10000 && Game::_boss == 0 && this->_sq->getCount() < 15)
	{
		Game::_boss = 1;
		this->_sq->push(new Boss(340, 45, 23, 23));
	}
	else if (time < 15 && Game::_boss % 2 == 0)
		this->_sq->push(new HorEnemy(360, y, 3, 3));
	else if (time < 40 && Game::_boss % 2 == 0)
	{
		choice = std::rand() % 2;
		if (choice == 0)
			this->_sq->push(new HorEnemy(360, y, 3, 3));
		else
			this->_sq->push(new MiniDiagEnemy(360, y, 3, 3));
	}
	else if ( Game::_boss % 2 == 0)
	{
		choice = std::rand() % 4;
		if (choice == 0)
			this->_sq->push(new HorEnemy(360, y, 3, 3));
		else if (choice == 1)
			this->_sq->push(new DiagEnemy(360, y, 3, 3));
		else if (choice == 2 )
			this->_sq->push(new ShootEnemy(360, y, 3, 3));
		else
			this->_sq->push(new MiniDiagEnemy(360, y, 3, 3));
	}
}

int	Game::_boss = 0;
