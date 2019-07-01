/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:16:02 by gmofoken          #+#    #+#             */
/*   Updated: 2017/12/13 11:16:12 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game() {}

Game::Game(int w, int h)
{
	quit = false;
	points = 0;
	width = w;
	height = h;

	srand(time(NULL));

	for (int i = 0; i < 5; i++)
  		snakes.push_front(Snake(3 + i, 3));
}

Game::Game(const Game & s)
{
	*this = s;
}

Game::~Game() {}

Game & Game::operator =(const Game &rhs)
{
	quit = rhs.quit;
	points = rhs.points;
	width = rhs.width;
	foodX = rhs.foodX;
	foodY = rhs.foodY;

	return *this;
}

void Game::initFood()
{
	foodX = rand() % width;
 	foodY = rand() % height;

    if (foodY <= 1 || foodX <= 0)
    {
       foodX = rand() % width;
       foodY = rand() % height;
    }
}

void Game::moveSnake(int dir)
{
	Snake logic = snakes.front();
	int x = logic.getX();
	int y = logic.getY();

	if (dir == 1)
		y--; // move up
	else if(dir == 2)
		x++; // move right
	else if(dir == 3)
		y++; // move down
	else if(dir == 4)
		x--; // move left
	else if (dir == 0)
		quit = true;

	snakes.push_front(Snake(x, y));

	if (x == foodX && y == foodY)
	{
		initFood();
		points++;
	} 
	else 
		snakes.pop_back();
    
    /* collision with border */
	if (y > height || x > width - 1 || y <= 1 || x < 1)
		quit = true;

	/* collision with snake */
	for (it = snakes.begin(); it != snakes.end(); it++)
	{
		if ((*it).getY() == y && (*it).getX() == x && it != snakes.begin())
    		quit = true;
	}
}

int Game::getFoodX()
{
	return foodX;
}

int Game::getFoodY()
{
	return foodY;
}

bool Game::hasEnded()
{
	return quit;
}

int Game::getPoints()
{
	return points;
}

std::list<Snake> Game::getSnake()
{
	return snakes;
}
