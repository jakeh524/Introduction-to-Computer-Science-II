//
//  Sequence.cpp
//  CS 32 Homework 1
//
//  Created by Jake Herron on 4/15/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//

#include "Sequence.h"
#include <iostream>
using namespace std;

Sequence::Sequence()
{
    m_len = 0;
}

void Sequence::dump() const
{
    for (int i = 0; i < size(); i++){
        cerr << m_arr[i] << " index: " << i << endl;
    }
}
bool Sequence::empty() const
{
    if (m_len == 0)
    {
        return(true);
    }
    return(false);
}

int Sequence::size() const
{
    return(m_len);
}

int Sequence::insert(int pos, const ItemType& value)
{
    if(pos >= 0 && pos <= size())
    {
        if(size() < DEFAULT_MAX_ITEMS)
        {
            m_len += 1;
            for(int i = size()-1; i >= pos; i--)
            {
                m_arr[i+1] = m_arr[i];
            }
            m_arr[pos] = value;
            return(pos);
        }
        return(-1);
    }
    return(-1);
}

int Sequence::insert(const ItemType& value)
{
    int p = size();
    for(int i = 0; i < size(); i++)
    {
        if(value <= m_arr[i])
        {
            p = i;
            break;
        }
    }
    return(insert(p, value));
}

bool Sequence::erase(int pos)
{
    if(pos >= 0 && pos < size())
    {
        for(int i = pos; i < size()-1; i++)
        {
            m_arr[i] = m_arr[i+1];
        }
        m_len -= 1;
        return(true);
    }
    return(false);
}

int Sequence::remove(const ItemType& value)
{
    int counter = 0;
    for(int i = 0; i < size(); i++)
    {
        if(m_arr[i] == value)
        {
            erase(i);
            counter += 1;
        }
    }
    return(counter);
}

bool Sequence::get(int pos, ItemType& value) const
{
    if(pos >= 0 && pos < size())
    {
        value = m_arr[pos];
        return(true);
    }
    return(false);
}

bool Sequence::set(int pos, const ItemType& value)
{
    if(pos >= 0 && pos < size())
    {
        m_arr[pos] = value;
        return(true);
    }
    return(false);
}

int Sequence::find(const ItemType& value) const
{
    int p = -1;
    for(int i = 0; i < size(); i++)
    {
        if(m_arr[i] == value)
        {
            p = i;
            return(p);
        }
    }
    return(p);
}

void Sequence::swap(Sequence& other)
{
    ItemType temp_arr[DEFAULT_MAX_ITEMS];
    int temp_len = m_len;
    m_len = other.m_len;
    other.m_len = temp_len;
    for(int i = 0; i < DEFAULT_MAX_ITEMS; i++)
    {
        temp_arr[i] = m_arr[i];
        m_arr[i] = other.m_arr[i];
        other.m_arr[i] = temp_arr[i];
    }
}
