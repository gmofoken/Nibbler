/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:17:24 by gmofoken          #+#    #+#             */
/*   Updated: 2017/12/13 11:17:28 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SNAKE_HPP
#define _SNAKE_HPP

class Snake
{
private:
	int x, y;
public:
	Snake();
	Snake(int a, int b);
	Snake(const Snake & s);
	~Snake();

	Snake & operator =(const Snake &rhs);

	int getX();
	int getY();
};

#endif
