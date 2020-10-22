//
//  Game.h
//  CS 32 Project 3
//
//  Created by Jake Herron on 5/14/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//

#ifndef Game_h
#define Game_h
#include "Board.h"
#include "Player.h"

class Game
{
public:
    Game(const Board& b, Player* south, Player* north);
    void display() const;
    void status(bool& over, bool& hasWinner, Side& winner) const;
    bool move();
    void play();
    int beans(Side s, int hole) const;
private:
    Board m_Board; // private board member
    Player* m_PlayerSouth; // pointer to south player
    Player* m_PlayerNorth; // pointer to north player
    Side m_turn; // whose turn is it
};

#endif /* Game_h */
