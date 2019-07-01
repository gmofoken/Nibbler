/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:18:14 by gmofoken          #+#    #+#             */
/*   Updated: 2017/12/13 11:18:17 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graphics.hpp"

Graphics::Graphics()
{
	dir = 2;

	initscr();
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
	timeout(100);
}

Graphics::Graphics(const Graphics & s)
{
	*this = s;
}

Graphics::~Graphics() {}

Graphics & Graphics::operator =(const Graphics &rhs)
{
	dir = rhs.dir;

	return *this;
}

void Graphics::drawBorder(int w, int h)
{
	mvhline(1 ,0, '+', w);
    vline('+', h);
    mvhline(h + 1, 0, '+', w - 1);
    mvvline(1 ,w, '+', h + 1);
}

int Graphics::getInput()
{
	int ch = getch();

	switch(ch) {
		case KEY_UP:
			dir = (dir == 3) ? 3 : 1;
		break;
		case KEY_RIGHT:
			dir = (dir == 4) ? 4 : 2;
		break;
		case KEY_DOWN:
			dir = (dir == 1) ? 1 : 3;
		break;
		case KEY_LEFT:
			dir = (dir == 2) ? 2 : 4;
		break;
		case 'q':
			dir = 0;
		break;
		case '1':
			dir = 5;
		break;
		case '2':
			dir = 6;
		break;
		case '3':
			dir = 7;
		break;
	}

	return dir;
}

void Graphics::printChar(int x, int y, char c)
{
	mvaddch(y, x, c);
}

void Graphics::printFood(int x, int y)
{
	mvaddch(y, x, '$');
}

void Graphics::clearScreen()
{
	erase();
}

void Graphics::printScore(int points)
{
	mvprintw(0, 0, "SCORE: %i. 'q' to quit.\n", points);
    refresh();
}

extern "C" IGraphics* create()
{
    return new Graphics;
}

extern "C" void destroy(IGraphics* g)
{
	timeout(-1);
    erase();
    mvprintw(0, 0, "You lost, game over!.\n");
	getch();
	attroff(COLOR_PAIR(1));
	refresh();
	endwin(); 
    delete g;
}
