/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:18:28 by gmofoken          #+#    #+#             */
/*   Updated: 2017/12/13 11:18:31 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GRAPHICS_HPP
#define _GRAPHICS_HPP

#include "IGraphics.hpp"

class Graphics: public IGraphics
{
private:
	int dir;

public:
	Graphics();
	Graphics(const Graphics & s);
	~Graphics();

	Graphics & operator =(const Graphics &rhs);

	virtual int getInput();
	virtual void drawBorder(int w, int h);
	virtual void printChar(int x, int y, char c);
	virtual void clearScreen();
	virtual void printScore(int points);
	virtual void printFood(int x, int y);
};

extern "C" IGraphics* create();
extern "C" void destroy(IGraphics* g);

#endif
