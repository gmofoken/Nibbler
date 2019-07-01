/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:16:18 by gmofoken          #+#    #+#             */
/*   Updated: 2017/12/13 11:16:21 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GAME_H
#define _GAME_H

#include <iostream>
#include <list>
#include <time.h>
#include <stdlib.h>

#include "Snake.hpp"

class Game
{
private:
	std::list<Snake> snakes;
	std::list<Snake>::iterator it;
	bool quit;
	int points, height, width, foodX, foodY;

public:
	Game();
	Game(int w, int h);
	Game(const Game & s);
	~Game();

	Game & operator =(const Game &rhs);

	void initFood();
	void moveSnake(int dir);

	bool hasEnded();
	int getFoodX();
	int getFoodY();
	int getPoints();
	std::list<Snake> getSnake();
};

#endif
