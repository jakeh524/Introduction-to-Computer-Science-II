//
//  Player.h
//  CS 32 Project 3
//
//  Created by Jake Herron on 5/14/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//

#ifndef Player_h
#define Player_h
#include "Board.h"
#include <string>
using namespace std;

class Player
{
public:
    Player(string name);
    string name() const;
    virtual bool isInteractive() const;
    virtual int chooseMove(const Board& b, Side s) const = 0;
    virtual ~Player();
    
private:
    string m_name; // private data to store name
};


class HumanPlayer : public Player // inherits from player
{
public:
    HumanPlayer(string name);
    virtual bool isInteractive() const;
    virtual int chooseMove(const Board& b, Side s) const;
    virtual ~HumanPlayer();
};


class BadPlayer : public Player // inherits from player
{
public:
    BadPlayer(string name);
    virtual bool isInteractive() const;
    virtual int chooseMove(const Board& b, Side s) const;
    virtual ~BadPlayer();
};


class SmartPlayer : public Player // inherits from player
{
public:
    SmartPlayer(string name);
    virtual bool isInteractive() const;
    virtual int chooseMove(const Board& b, Side s) const;
    virtual ~SmartPlayer();
private:
    bool hasThisSideWon(const Board& b, Side s) const; // will check if a side has won yet
    int maximize(const Board& b, Side s, int depthTracker) const; // will be used to maximize the smart players score
    int minimize(const Board& b, Side s, int depthTracker) const; // will be used to minimize the opponents score
    
};

#endif /* Player_h */
