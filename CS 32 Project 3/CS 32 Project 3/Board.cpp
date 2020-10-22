//
//  Board.cpp
//  CS 32 Project 3
//
//  Created by Jake Herron on 5/13/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//


#include "Board.h"
#include <vector>
using namespace std;

Board::Board(int nHoles, int nInitialBeansPerHole)
{
    
    if(nHoles > 0 && nInitialBeansPerHole >= 0) // for legal holes and initial beans
    {
        m_nHoles = nHoles; // assign holes numbers
        m_northVector.assign(nHoles, nInitialBeansPerHole); // for north and south create vector with holes and init beans
        m_southVector.assign(nHoles, nInitialBeansPerHole);
        m_northVector.insert(m_northVector.begin(), 0); // insert the empty pots at the beginning for each side
        m_southVector.insert(m_southVector.begin(), 0);
    }
    else if(nHoles > 0 && nInitialBeansPerHole < 0) // for legal holes and non legal init beans
    {
        m_nHoles = nHoles;
        m_northVector.assign(nHoles, 0); // for non legal init beans put 0
        m_southVector.assign(nHoles, 0);
        m_northVector.insert(m_northVector.begin(), 0);
        m_southVector.insert(m_southVector.begin(), 0);
    }
    else if(nHoles <= 0 && nInitialBeansPerHole >= 0) // for non legal holes and legal init holes
    {
        m_nHoles = 1; // treat holes as 1 for non legal holes
        m_northVector.assign(1, nInitialBeansPerHole);
        m_southVector.assign(1, nInitialBeansPerHole);
        m_northVector.insert(m_northVector.begin(), 0);
        m_southVector.insert(m_southVector.begin(), 0);
    }
    else if(nHoles <= 0 && nInitialBeansPerHole < 0) // for non legal holes and init beans
    {
        m_nHoles = 1; // treat holes as 1
        m_northVector.assign(1, 0); // treat init beans as 0
        m_southVector.assign(1, 0);
        m_northVector.insert(m_northVector.begin(), 0);
        m_southVector.insert(m_southVector.begin(), 0);
    }
}

Board::Board(const Board& other) // copy constructor for board
{
    m_nHoles = other.m_nHoles; // assing hole num
    m_northVector.assign(m_nHoles+1, -1); // create vectors for both sides with placeholder beans
    m_southVector.assign(m_nHoles+1, -1);
    for(int i = 0; i <= m_nHoles; i++) // iterate through the holes and pot and copy over beans
    {
        m_northVector.at(i) = other.m_northVector.at(i);
        m_southVector.at(i) = other.m_southVector.at(i);
    }
}


int Board::holes() const
{
    return(m_nHoles); // just a getter func
}

int Board::beans(Side s, int hole) const
{
    if(hole >= 0 && hole <= m_nHoles) // if the hole is valid
    {
        if(s == NORTH)
        {
            return(m_northVector.at(hole)); // return beans at hole for north
        }
        else if(s == SOUTH)
        {
            return(m_southVector.at(hole)); // return beans at hole for south
        }
    }
    return(-1); // if the hole isnt valid return -1
}

int Board::beansInPlay(Side s) const
{
    if(s == NORTH)
    {
        int northTotal = 0;
        for(int i = 1; i < m_northVector.size(); i++) // add up all the beans on the north side in the holes and return total
        {
            northTotal += m_northVector.at(i);
        }
        return(northTotal);
    }
    else if(s == SOUTH)
    {
        int southTotal = 0;
        for(int i = 1; i < m_southVector.size(); i++) // add up all the beans on the south side in the holes and return total
        {
            southTotal += m_southVector.at(i);
        }
        return(southTotal);
    }
    return(-1); // only here to avoid compilation error ; should never return this
}

int Board::totalBeans() const
{
    int overallTotal = 0;
    for(int i = 0; i < m_northVector.size(); i++) // add up all beans and pot from north side
    {
        overallTotal += m_northVector.at(i);
    }
    for(int i = 0; i < m_southVector.size(); i++) // add up all beans and pot from south side
    {
        overallTotal += m_southVector.at(i);
    }
    return(overallTotal);
}

bool Board::sow(Side s, int hole, Side& endSide, int& endHole)
{
    if(hole <= 0 || hole > m_nHoles) // the following three if statements check to make sure the hole number is valid and that its not empty
    {
        return(false);
    }
    if(s == NORTH) // check if there are no beans
    {
        if(m_northVector.at(hole) == 0)
        {
            return(false);
        }
    }
    else if(s == SOUTH) // check if there are no beans
    {
        if(m_southVector.at(hole) == 0)
        {
            return(false);
        }
    }
    
    // we have a valid hole
    int beansToBeSown = 0;
    endHole = hole;
    if(s == NORTH)
    {
        beansToBeSown = m_northVector.at(hole); // take beans out of hole and put it in variable
        m_northVector.at(hole) = 0;
        endSide = NORTH;
        for(int i = hole-1; i >= 0 && beansToBeSown > 0; i--, endHole--) // go through the remaining of the north side
        {
            m_northVector.at(i) += 1; // add a bean and subtract from our counter
            beansToBeSown--;
        }
        while(beansToBeSown > 0) // go around and around until we are out of beans
        {
            if(beansToBeSown > 0)
            {
                endSide = SOUTH; // reassign endside cause we are switching sides
                for(int i = 1; i <= m_nHoles && beansToBeSown > 0; i++, endHole++) // go through the south side in full (skipping the pot)
                {
                    m_southVector.at(i) += 1;
                    beansToBeSown--;
                }
            }
            if(beansToBeSown > 0)
            {
                endSide = NORTH;
                endHole = m_nHoles;
                for(int i = m_nHoles; i >= 0 && beansToBeSown > 0; i--, endHole--) // go through the north side in full (including the pot)
                {
                    m_northVector.at(i) += 1;
                    beansToBeSown--;
                }
            }
        }
    }
    else if(s == SOUTH)
    {
        beansToBeSown = m_southVector.at(hole); // take beans out of hole and put it in variable
        m_southVector.at(hole) = 0;
        endSide = SOUTH;
        for(int i = hole+1; i <= m_nHoles && beansToBeSown > 0; i++, endHole++) // go through the remaining of the south side
        {
            m_southVector.at(i) += 1;
            beansToBeSown--;
        }
        while(beansToBeSown > 0) // go around and around until we are out of beans
        {
            m_southVector.at(0) += 1; // handle south's pot because its numbering is set up weirdly
            beansToBeSown--;
            if(beansToBeSown == 0)
            {
                endHole = 0; // if our last bean was put in the pot break out of the loop
                break;
            }
            if(beansToBeSown > 0)
            {
                endHole = m_nHoles+1;
                endSide = NORTH;
                for(int i = m_nHoles; i >= 1 && beansToBeSown > 0; i--, endHole--) // go through the north side in full (skipping the pot)
                {
                    m_northVector.at(i) += 1;
                    beansToBeSown--;
                }
            }
            if(beansToBeSown > 0)
            {
                endHole = 0;
                endSide = SOUTH;
                for(int i = 1; i <= m_nHoles && beansToBeSown > 0; i++, endHole++) // go through the south side in full (including the pot)
                {
                    m_southVector.at(i) += 1;
                    beansToBeSown--;
                }
            }
        }
    }
    return(true); // we made a move correctly
}

bool Board::moveToPot(Side s, int hole, Side potOwner)
{
    if(hole > m_nHoles || hole <= 0) // make sure its a valid pot
    {
        return(false);
    }
    if(potOwner == NORTH)
    {
        if(s == NORTH) // if moving north hole to north pot
        {
            m_northVector[0] += m_northVector.at(hole); // take beans and put it in pot and empty hole
            m_northVector.at(hole) = 0;
        }
        else if(s == SOUTH) // if moving south hole to north pot
        {
            m_northVector[0] += m_southVector.at(hole);
            m_southVector.at(hole) = 0;
        }
    }
    else if(potOwner == SOUTH)
    {
        if(s == NORTH) // if moving north hole to south pot
        {
            m_southVector[0] += m_northVector.at(hole);
            m_northVector.at(hole) = 0;
        }
        else if(s == SOUTH) // if moving south hole to south pot
        {
            m_southVector[0] += m_southVector.at(hole);
            m_southVector.at(hole) = 0;
        }
    }
    return(true); // our func did something right
}

bool Board::setBeans(Side s, int hole, int beans)
{
    if(hole > m_nHoles || hole < 0) // if hole is valid
    {
        return(false);
    }
    if(beans < 0) // if beans is valid
    {
        return(false);
    }
    if(s == NORTH) // set the beans at that hole for each side
    {
        m_northVector.at(hole) = beans;
    }
    else if(s == SOUTH)
    {
        m_southVector.at(hole) = beans;
    }
    return(true); // we did the function right
}
