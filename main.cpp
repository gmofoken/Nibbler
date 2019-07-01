/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:17:53 by gmofoken          #+#    #+#             */
/*   Updated: 2017/12/13 11:17:55 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <dlfcn.h>
#include "Game.hpp"
#include "IGraphics.hpp"

destroy_t* destroy_graphics;

create_t* createGraphics(void* graphics)
{   
    // load the symbols
    create_t* create_graphics = (create_t*)dlsym(graphics, "create");
    const char* dlsym_error = dlerror();

    if (dlsym_error)
    {
        std::cerr << "Cannot load symbol create: " << dlsym_error << std::endl;
        return NULL;
    }

    return create_graphics;
}

destroy_t* destroyGraphics(void* graphics)
{  
    destroy_graphics = (destroy_t*) dlsym(graphics, "destroy");
    const char* dlsym_error = dlerror();

    if (dlsym_error)
    {
        std::cerr << "Cannot load symbol destroy: " << dlsym_error << std::endl;
        return NULL;
    }

    return destroy_graphics;
}

void gamePlay(IGraphics *g, int w, int h)
{
    Game snakeGame = Game(w, h);
    std::list<Snake> snake;
    std::list<Snake>::iterator it;

    snakeGame.initFood();

    while (!snakeGame.hasEnded())
    {
        g->drawBorder(w, h);

        int dir = g->getInput();

        if (dir > 4 && dir < 8)
        {
            const char* lib;
            
            if (dir == 5)
                lib = "./lib1/ncurses.so";
            else if (dir == 6)
                lib = "./lib2/ncurses2.so";
            else
                lib = "./lib3/ncurses3.so";

            void* graphics = dlopen(lib, RTLD_LAZY);

            if (!graphics)
            {
                std::cerr << "Cannot load library: " << dlerror() << std::endl;
                return;
            }

            dlerror();

            create_t* create_graphics = createGraphics(graphics);
            destroy_graphics = destroyGraphics(graphics);

            if (create_graphics == NULL || destroy_graphics == NULL)
                return;

            g = create_graphics();
        }
        else
        {
            snakeGame.moveSnake(dir);
            g->clearScreen();
            g->printFood(snakeGame.getFoodX(), snakeGame.getFoodY());

            snake = snakeGame.getSnake();
            /* Print snake */
            for(it = snake.begin(); it != snake.end(); it++)
                g->printChar(it->getX(), it->getY(), 'o');

            g->printScore(snakeGame.getPoints());
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "Usage: " << argv[0] << " [width] [height]" << std::endl;
        return (1);
    }

    void* graphics = dlopen("./lib1/ncurses.so", RTLD_LAZY);

    if (!graphics)
    {
        std::cerr << "Cannot load library: " << dlerror() << std::endl;
        return 0;
    }

    // reset errors
    dlerror();

    create_t* create_graphics = createGraphics(graphics);
    destroy_graphics = destroyGraphics(graphics);

    if (create_graphics == NULL || destroy_graphics == NULL)
        return (1);

    IGraphics* g = create_graphics();

    int i = 0;
    while (argv[1][i])
    {
        if (!isdigit(argv[1][i]))
        {
            std::cout << "enter numeric values only" <<std::endl;
            return (1);
        }
        i++;

    }
    
    int k = 0;
    while (argv[2][k])
    {
        if (!isdigit(argv[2][k]))
        {
            std::cout << "enter numeric values only" <<std::endl;
            return (1);
        }
        k++;

    }
   int w = std::stoi(argv[1]);
   int h = std::stoi(argv[2]);

   //Ensure minimum size 
   if(w < 20 || h < 20){
        std::cout << "Minimum size is 20 x 20! " <<std::endl;
        return (1);
   }
     if(w > 200 || h > 60){
        std::cout << "Max width is 200 and Max height is 60... pleae adjust accordingly! " <<std::endl;
        return (1);
   }else{
        gamePlay(g, w, h);
   }
    
    //gamePlay(g);
    //g->drawBorder(80, 24);
    //g->getInput();
    destroy_graphics(g);

    // unload the graphics library
    dlclose(g);

	return 0;
}
