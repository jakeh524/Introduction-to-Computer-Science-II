//
//  newSequence.cpp
//  CS 32 Homework 1
//
//  Created by Jake Herron on 4/15/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//

#include "newSequence.h"
#include <iostream>
using namespace std;

Sequence::Sequence(int len)
{
    if(len < 0)
    {
        cout << "The Sequence cannot have a negative length." << endl;
        exit(1);
    }
    m_len = 0;
    m_maxLen = len;
    m_arr = new ItemType[m_maxLen];
}

Sequence::~Sequence()
{
    delete [] m_arr;
}

Sequence::Sequence(const Sequence& other)
{
    m_len = other.m_len;
    m_maxLen = other.m_maxLen;
    m_arr = new ItemType[m_maxLen];
    for(int i = 0; i < m_len; i++)
    {
        m_arr[i] = other.m_arr[i];
    }
}

Sequence& Sequence::operator=(const Sequence& rhs)
{
    Sequence temp(rhs);
    swap(temp);
    return *this;
}

void Sequence::dump() const
{
    for (int i = 0; i < size(); i++){
        cerr << m_arr[i] << endl;
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

int Sequence::insert(int pos, const ItemType& value) // i dont know if anyone is going to read this on a homework but this ran correctly on xcode but g32 gave me AddressSanitizer errors and I have no clue how to fix it sorry :)
{
    if(pos >= 0 && pos <= size())
    {
        if(m_maxLen > size())
        {
            m_len += 1;
            for(int i = size()-1; i >= pos; i--)
            {
                m_arr[i+1] = m_arr[i];
            }
            m_arr[pos] = value;
            return(pos);
        }
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
    ItemType* temp_arr = m_arr;
    m_arr = other.m_arr;
    other.m_arr = temp_arr;
    int temp_len = m_len;
    m_len = other.m_len;
    other.m_len = temp_len;
    int temp_maxLen = m_maxLen;
    m_maxLen = other.m_maxLen;
    other.m_maxLen = temp_maxLen;
}
