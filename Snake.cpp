/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:17:15 by gmofoken          #+#    #+#             */
/*   Updated: 2017/12/13 11:17:17 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snake.hpp"

Snake::Snake() {}

Snake::Snake(int a, int b)
{
   x = a;
   y = b;
}

Snake::Snake(const Snake & s)
{
	*this = s;
}

Snake::~Snake() {}

Snake & Snake::operator =(const Snake &rhs)
{
	x = rhs.x;
	y = rhs.y;

	return *this;
}

int Snake::getX()
{
	return x;
}
 
int Snake::getY()
{
	return y;
}
