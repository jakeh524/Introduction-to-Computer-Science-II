//
//  mazequeue.cpp
//  CS 32 HW 2
//
//  Created by Jake Herron on 5/1/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//

#include <queue>
#include <iostream>
using namespace std;

class Coord
{
public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
private:
    int m_r;
    int m_c;
};

bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
    queue<Coord> coordQueue;
    coordQueue.push(Coord(sr, sc));
    maze[sr][sc] = 'o';
    while(coordQueue.empty() != true)
    {
        Coord currentCoord = coordQueue.front();
        coordQueue.pop();
        if(currentCoord.r() == er && currentCoord.c() == ec)
        {
            return(true);
        }
        if(maze[currentCoord.r()+1][currentCoord.c()] == '.')
        {
            coordQueue.push(Coord(currentCoord.r()+1, currentCoord.c()));
            maze[currentCoord.r()+1][currentCoord.c()] = 'o';
        }
        if(maze[currentCoord.r()][currentCoord.c()-1] == '.')
        {
            coordQueue.push(Coord(currentCoord.r(), currentCoord.c()-1));
            maze[currentCoord.r()][currentCoord.c()-1] = 'o';
        }
        if(maze[currentCoord.r()-1][currentCoord.c()] == '.')
        {
            coordQueue.push(Coord(currentCoord.r()-1, currentCoord.c()));
            maze[currentCoord.r()-1][currentCoord.c()] = 'o';
        }
        if(maze[currentCoord.r()][currentCoord.c()+1] == '.')
        {
            coordQueue.push(Coord(currentCoord.r(), currentCoord.c()+1));
            maze[currentCoord.r()][currentCoord.c()+1] = 'o';
        }
    }
    return(false);
}

int main()
{
    char maze[10][10] = {
        { 'X','X','X','X','X','X','X','X','X','X' },
        { 'X','.','.','.','.','X','.','.','.','X' },
        { 'X','.','X','X','.','X','X','X','.','X' },
        { 'X','X','X','.','.','.','.','X','.','X' },
        { 'X','.','X','X','X','.','X','X','X','X' },
        { 'X','.','X','.','.','.','X','.','.','X' },
        { 'X','.','.','.','X','.','X','.','.','X' },
        { 'X','X','X','X','X','.','X','.','X','X' },
        { 'X','.','.','.','.','.','.','.','.','X' },
        { 'X','X','X','X','X','X','X','X','X','X' }
    };
    
    if (pathExists(maze, 3,5, 8,8))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
}
