//
//  Game.h
//  CS 32 Project 1
//
//  Created by Jake Herron on 4/3/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//

#ifndef GAME_H
#define GAME_H
#include "Arena.h"
class Game
{
public:
    // Constructor/destructor
    Game(int rows, int cols, int nZombies);
    ~Game();
    
    // Mutators
    void play();
    
private:
    Arena* m_arena;
};

int decodeDirection(char dir);
#endif
