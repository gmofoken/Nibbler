/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake1.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:17:38 by gmofoken          #+#    #+#             */
/*   Updated: 2017/12/13 11:17:41 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

class snake {
 private:
  int x, y;
 public:
  snake(int a, int b) {
   x = a;
   y = b;
  }
  int getX() { return x; }
  int getY() { return y; }
}; 

int main() {
 // Init
 srand ( time(NULL) ); 
 initscr();
 noecho();
 curs_set(0);
 keypad(stdscr, TRUE);
 timeout(100);
 

 std::list<snake> snakes;
 std::list<snake>::iterator it;
 bool quit = false;
 int points = 0;
 int dir = 2;
 int food_x = rand() % 80;
 int food_y = rand() % 24;
    if(food_y >= 25 || food_y <= 1 || food_x >= 80 || food_x <= 0)
    {
       food_x = rand() % 80;
       food_y = rand() % 24;
    }

 int ch;
int height = 24;
int width = 81;
int start_y = 1;
int start_x = 0;

 for(int i = 0; i < 5; i++) // generate start snake
  snakes.push_front(snake(3+i,3));
 while(!quit) {
     // Input
    mvhline(1 ,0, '*', 81);
    vline('*', 24);
    mvhline(25 ,0, '*', 80);
    mvvline(1 ,81, '*', 25);
    //box(stdscr, 'H', '=');
    //wrefresh(win);
     ch = getch();
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
       quit = true;
       break;
     }
     
     // Logic
     snake logic = snakes.front();
     int x = logic.getX();
     int y = logic.getY();
     if(dir == 1) y--; // move up
     else if(dir == 2) x++; // move right
     else if(dir == 3) y++; // move down
     else if(dir == 4) x--; // move left
     snakes.push_front(snake(x, y));
     //After eating
     if(x == food_x && y == food_y) 
     {
       food_x = rand() % 80;
       food_y = rand() % 24;
       
       if(food_y >= 25 || food_y <= 1 || food_x >= 80 || food_x <= 0)
       {
          food_x = rand() % 80;
          food_y = rand() % 24;
       }
       points++;
     } 
     else 
      snakes.pop_back();
      
     if(y > 24 || x > 80 || y < 2 || x < 1) // collision with border
      quit = true;
     // Output
     erase();
     mvaddch(food_y,food_x,'X');
     for(it = snakes.begin(); it != snakes.end(); it++) {
      mvaddch((*it).getY(),(*it).getX(),'o');
      if((*it).getY() == y && (*it).getX() == x && it != snakes.begin()) // collision with snake
       quit = true;
     }
     mvprintw(0, 0, "SCORE: %i . 'q' to quit.\n", points);
      mvprintw(0, 31, "X Position is : %i\n", food_x);
     mvprintw(0, 50, "Y Position is : %i\n", food_y);
     refresh();
    
    }
    timeout(-1);
    erase();
    mvprintw(0, 0, "You lost and gained a total of %i points.\n", points);
    getch(); // wait for input
    refresh();

 endwin(); 
 return 0;
}
