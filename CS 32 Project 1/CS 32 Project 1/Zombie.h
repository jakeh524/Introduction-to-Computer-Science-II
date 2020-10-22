//
//  Zombie.h
//  CS 32 Project 1
//
//  Created by Jake Herron on 4/3/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//

#ifndef ZOMBIE_H
#define ZOMBIE_H
class Arena;
class Zombie
{
public:
    // Constructor
    Zombie(Arena* ap, int r, int c);
    
    // Accessors
    int  row() const;
    int  col() const;
    
    // Mutators
    void move();
    bool getAttacked(int dir);
    
private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    int    m_health;
};


#endif
