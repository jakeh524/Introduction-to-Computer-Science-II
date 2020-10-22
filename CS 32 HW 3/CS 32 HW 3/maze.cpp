//
//  maze.cpp
//  CS 32 HW 3
//
//  Created by Jake Herron on 5/10/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//

bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
    if(sr == er && sc == ec)
    {
        return(true);
    }
    maze[sr][sc] = 'o';
    if(maze[sr+1][sc] == '.')
    {
        if(pathExists(maze, sr+1, sc, er, ec) == true)
        {
            return(true);
        }
    }
    if(maze[sr][sc-1] == '.')
    {
        if(pathExists(maze, sr, sc-1, er, ec) == true)
        {
            return(true);
        }
    }
    if(maze[sr-1][sc] == '.')
    {
        if(pathExists(maze, sr-1, sc, er, ec) == true)
        {
            return(true);
        }
    }
    if(maze[sr][sc+1] == '.')
    {
        if(pathExists(maze, sr, sc+1, er, ec) == true)
        {
            return(true);
        }
    }
    return(false);
}
