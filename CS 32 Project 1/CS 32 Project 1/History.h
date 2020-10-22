//
//  History.h
//  CS 32 Project 1
//
//  Created by Jake Herron on 4/8/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//

#ifndef History_h
#define History_h
#include "globals.h"
class History
{
public:
    History(int nRows, int nCols);
    bool record(int r, int c);
    void display() const;
private:
    int m_Rows;
    int m_Cols;
    int grid[MAXROWS][MAXCOLS];
};

#endif /* History_h */
