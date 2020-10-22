//
//  Arena.h
//  CS 32 Project 1
//
//  Created by Jake Herron on 4/3/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//

#ifndef ARENA_H
#define ARENA_H
//#include "Player.h"
#include "globals.h"
#include "History.h"
class Zombie;
class Player;
class Arena
{
public:
    // Constructor/destructor
    Arena(int nRows, int nCols);
    ~Arena();
    
    // Accessors
    int     rows() const;
    int     cols() const;
    Player* player() const;
    int     zombieCount() const;
    int     numZombiesAt(int r, int c) const;
    bool    determineNewPosition(int& r, int& c, int dir) const;
    void    display() const;
    
    // Mutators
    bool   addZombie(int r, int c);
    bool   addPlayer(int r, int c);
    bool   attackZombieAt(int r, int c, int dir);
    bool   moveZombies();
    
    History& history();
private:
    int     m_rows;
    int     m_cols;
    Player* m_player;
    Zombie* m_zombies[MAXZOMBIES];
    int     m_nZombies;
    History m_history;
};

#endif
