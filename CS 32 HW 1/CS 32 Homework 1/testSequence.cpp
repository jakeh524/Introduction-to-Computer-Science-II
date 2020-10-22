//
//  testSequence.cpp
//  CS 32 Homework 1
//
//  Created by Jake Herron on 4/15/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//

#include "Sequence.h"
#include <iostream>
#include <cassert>
using namespace std;

void test()
{
    Sequence s;
    assert(s.empty() == true);
    assert(s.size() == 0);
    s.insert(0, 10);
    s.insert(0, 20);
    assert(s.size() == 2);
    assert(s.empty() == false);
    ItemType x = 999;
    assert(s.get(0, x) && x == 20);
    assert(s.get(1, x) && x == 10);
    s.insert(1);
    s.insert(15);
    s.insert(3, 30);
    assert(s.size() == 5); // 1 15 20 30 10
//    for (int i = 0; i < s.size(); i++)
//    {
//        ItemType y = 888;
//        s.get(i, y);
//        cout << y << endl;
//    }
    assert(s.get(0, x) && x == 1);
    assert(s.get(1, x) && x == 15);
    assert(s.get(3, x) && x == 30);
    assert(s.insert(75, 99) == -1);
    s.erase(0);
    assert(s.get(0, x) && x == 15);
    assert(s.erase(77) == false);
    assert(s.remove(33) == 0);
    s.insert(4, 15);
    assert(s.size() == 5);
    assert(s.get(4, x) && x == 15);
    s.remove(15);
    assert(s.size() == 3);
    assert(s.get(0, x) && x == 20);
    assert(s.get(100, x) == false);
    assert(s.set(100, 44) == false);
    s.set(0, 21);
    assert(s.get(0, x) && x == 21);
    assert(s.find(21) == 0);
    assert(s.find(69) == -1);
    Sequence t;
    t.insert(0, 5);
    t.insert(0, 4);
    t.insert(0, 3);
    t.insert(0, 2);
    t.insert(0, 1);
    t.insert(0, 0);
    s.swap(t);
    assert(s.get(0, x) && x == 0);
    assert(s.get(1, x) && x == 1);
    assert(s.get(2, x) && x == 2);
    assert(s.get(3, x) && x == 3);
    assert(s.get(4, x) && x == 4);
    assert(s.get(5, x) && x == 5);
}

int main()
{
    test();
}
