//
//  Board.h
//  CS 32 Project 3
//
//  Created by Jake Herron on 5/13/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//

#ifndef Board_h
#define Board_h

#include "Side.h"
#include <vector>
using namespace std;

class Board
{
public:
    Board(int nHoles, int nInitialBeansPerHole);
    Board(const Board& other); // copy constructor for Board
    int holes() const;
    int beans(Side s, int hole) const;
    int beansInPlay(Side s) const;
    int totalBeans() const;
    bool sow(Side s, int hole, Side& endSide, int& endHole);
    bool moveToPot(Side s, int hole, Side potOwner);
    bool setBeans(Side s, int hole, int beans);

private:
    int m_nHoles; // private member to store holes
    vector<int> m_northVector; // vector to store north's holes and pot
    vector<int> m_southVector; // vector to store south's holes and pot
};

#endif /* Board_h */
