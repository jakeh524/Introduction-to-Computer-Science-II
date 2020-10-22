//
//  testScoreList.cpp
//  CS 32 Homework 1
//
//  Created by Jake Herron on 4/15/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//

#include <iostream>
#include "ScoreList.h"
#include <cassert>
using namespace std;

void test()
{
    ScoreList Scores;
    assert(Scores.size() == 0);
    Scores.add(75);
    Scores.add(50);
    Scores.add(25);
    assert(Scores.size() == 3);
    assert(Scores.add(101) == false);
    Scores.remove(50);
    assert(Scores.size() == 2);
    assert(Scores.remove(80) == false);
    assert(Scores.minimum() == 25);
    assert(Scores.maximum() == 75);
    
    ScoreList List;
    assert(List.size() == 0);
    assert(List.minimum() == NO_SCORE);
    assert(List.maximum() == NO_SCORE);
}

int main()
{
    test();
}
