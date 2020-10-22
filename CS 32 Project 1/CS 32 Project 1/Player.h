//
//  Player.h
//  CS 32 Project 1
//
//  Created by Jake Herron on 4/3/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//

#ifndef PLAYER_H
#define PLAYER_H
class Arena;
class Player
{
public:
    // Constructor
    Player(Arena *ap, int r, int c);
    
    // Accessors
    int  row() const;
    int  col() const;
    int  age() const;
    bool isDead() const;
    
    // Mutators
    void   stand();
    void   moveOrAttack(int dir);
    void   setDead();
    
private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    int    m_age;
    bool   m_dead;
};

#endif
