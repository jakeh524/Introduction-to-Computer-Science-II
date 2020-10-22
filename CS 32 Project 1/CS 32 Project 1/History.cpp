//
//  History.cpp
//  CS 32 Project 1
//
//  Created by Jake Herron on 4/8/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//

#include "History.h"
#include "globals.h"
#include <iostream>
using namespace std;

History::History(int nRows, int nCols) : m_Rows(nRows), m_Cols(nCols)
{
    int r, c;
    // Fill the grid with dots
    for (r = 0; r < m_Rows; r++)
        for (c = 0; c < m_Cols; c++)
            grid[r][c] = 0;
}

bool History::record(int r, int c)
{
    if(r <= m_Rows && c <= m_Cols)
    {
        grid[r-1][c-1] += 1;
        return true;
    }
    return false;
}

void History::display() const
{
    clearScreen();
    for (int r = 0; r < m_Rows; r++)
    {
        for (int c = 0; c < m_Cols; c++)
        {
            if(grid[r][c] == 0)
            {
                cout << '.';
            }
            else if(grid[r][c] >= 26)
            {
                cout << 'Z';
            }
            else if (grid[r][c] >= 1)
            {
                cout << char('@' + grid[r][c]);
            }
        }
        cout << endl;
    }
    cout << endl;
}


