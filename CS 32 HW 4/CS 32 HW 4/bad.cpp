//
//  bad.cpp
//  CS 32 HW 4
//
//  Created by Jake Herron on 5/28/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//

void removeBad(list<Movie*>& li)
{
    list<Movie*>::iterator it = li.begin();
    for(; it != li.end();)
    {
        if((*it)->rating() < 55)
        {
            (*it)->~Movie();
            it = li.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

