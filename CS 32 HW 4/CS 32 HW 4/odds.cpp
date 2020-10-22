//
//  odds.cpp
//  CS 32 HW 4
//
//  Created by Jake Herron on 5/28/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//

void removeOdds(vector<int>& v)
{
    vector<int>::iterator it = v.begin();
    for(; it != v.end();)
    {
        if(*it % 2 != 0)
        {
            it = v.erase(it);
        }
        else
        {
            ++it;
        }
    }
}
