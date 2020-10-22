//
//  testnewSequence.cpp
//  CS 32 Homework 1
//
//  Created by Jake Herron on 4/15/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//

#include "newSequence.h"
#include <iostream>
#include <cassert>
using namespace std;

void test()
{
    Sequence s(3);
    s.insert(0, 1);
    s.insert(0, 0);
    assert(s.size() == 2);
    
    Sequence z(s);
    assert(z.size() == s.size());
    ItemType x = 999;
    ItemType y = 888;
    s.get(0, x);
    z.get(0, y);
    assert(x==y);
    
    Sequence t(5);
    t = s;
    assert(t.size() == s.size());
    ItemType a = 111;
    ItemType b = 222;
    s.get(0, a);
    t.get(0, b);
    assert(a==b);
    
    Sequence j(7);
    j.insert(0, 4);
    j.insert(0, 3);
    j.insert(0, 2);
    j.insert(0, 1);
    j.insert(0, 0);
    j.swap(s);
    assert(j.size() == 2);
    ItemType i = 555;
    j.get(0, i);
    assert(i == 0);
    assert(s.size() == 5);
    
    s.insert(5, 5);
    s.insert(6, 6);
    assert(s.insert(7, 7) == -1);
    
    
}

int main()
{
    test();
}
