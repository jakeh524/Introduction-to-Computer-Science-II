//
//  list.cpp
//  CS 32 HW 4
//
//  Created by Jake Herron on 5/28/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//

void listAll(const Domain* d, string path) // two-parameter overload
{
    if(d->subdomains().size() == 0)
    {
        cout << path << endl;
        return;
    }
    string oldPath = path;
    for(vector<Domain*>::const_iterator it = d->subdomains().cbegin(); it != d->subdomains().cend(); it++)
    {
        
        if(path != "")
        {
            path = (*it)->label() + "." + path;
            listAll(*it, path);
        }
        else
        {
            path = (*it)->label() + path;
            listAll(*it, path);
        }
        path = oldPath;
    }
}
