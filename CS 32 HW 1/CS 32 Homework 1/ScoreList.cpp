//
//  ScoreList.cpp
//  CS 32 Homework 1
//
//  Created by Jake Herron on 4/15/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//

#include "ScoreList.h"

ScoreList::ScoreList()
{
    Sequence m_seq;
}

bool ScoreList::add(unsigned long score)
{
    if(score <= 100)
    {
        m_seq.insert(score);
        return(true);
    }
    return(false);
}

bool ScoreList::remove(unsigned long score)
{
    int pos = m_seq.find(score);
    if(pos != -1)
    {
        m_seq.erase(pos);
        return(true);
    }
    return(false);
}

int ScoreList::size() const
{
    return(m_seq.size());
}

unsigned long ScoreList::minimum() const
{
    if(m_seq.empty() == true)
    {
        return(NO_SCORE);
    }
    unsigned long currentMin = 101;
    for(int i = 0; i < size(); i++)
    {
        unsigned long currentValue;
        m_seq.get(i, currentValue);
        if(currentValue < currentMin)
        {
            currentMin = currentValue;
        }
    }
    return(currentMin);
}

unsigned long ScoreList::maximum() const
{
    if(m_seq.empty() == true)
    {
        return(NO_SCORE);
    }
    unsigned long currentMax = 0;
    for(int i = 0; i < size(); i++)
    {
        unsigned long currentValue;
        m_seq.get(i, currentValue);
        if(currentValue > currentMax)
        {
            currentMax = currentValue;
        }
    }
    return(currentMax);
}
