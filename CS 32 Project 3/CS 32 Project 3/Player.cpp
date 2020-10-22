//
//  Player.cpp
//  CS 32 Project 3
//
//  Created by Jake Herron on 5/14/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//

#include "Player.h"
#include <iostream>
#include <limits>

Player::Player(string name) // basic constructor just put name into data member
{
    m_name = name;
}

string Player::name() const // simple getter func
{
    return(m_name);
}

bool Player::isInteractive() const // we are just saying that a basic player is not interactive. this will never be called
{
    return(false);
}

Player::~Player() // basic destructor
{}

////////////////////

HumanPlayer::HumanPlayer(string name) : Player(name) // have to construct like this because of inheritance
{}

bool HumanPlayer::isInteractive() const // our human player is interactive
{
    return(true);
}

int HumanPlayer::chooseMove(const Board& b, Side s) const
{
    int sumOfHolesMe = 0;
    for(int i = 1; i <= b.holes(); i++)
    {
        sumOfHolesMe += b.beans(s, i);
    }
    int sumOfHolesYou = 0;
    for(int i = 1; i <= b.holes(); i++)
    {
        sumOfHolesYou += b.beans(opponent(s), i);
    }
    if(sumOfHolesMe == 0 || sumOfHolesYou == 0) // add up the beans in both sides and check if either side total to zero cause then its an invalid board and will return -1
    {
        return(-1);
    }
    bool validMoveChosen = false;
    int move = -1; // initialize to -1 ; it should never return -1
    while(validMoveChosen == false) // loop through and take our input and check if its valid. if its not valid then stay in the while loop
    {
        cout << "Choose a hole: ";
        cin >> move;
        if(move > 0 && move <= b.holes())
        {
            validMoveChosen = true;
        }
    }
    return(move); // return the move
}

HumanPlayer::~HumanPlayer() // destructor for human player
{}

////////////////////

BadPlayer::BadPlayer(string name) : Player(name) // constructor is like this because of inheritance
{}

bool BadPlayer::isInteractive() const // bad player is not interactive
{
    return(false);
}

int BadPlayer::chooseMove(const Board& b, Side s) const
{
    int sumOfHolesMe = 0;
    for(int i = 1; i <= b.holes(); i++)
    {
        sumOfHolesMe += b.beans(s, i);
    }
    int sumOfHolesYou = 0;
    for(int i = 1; i <= b.holes(); i++)
    {
        sumOfHolesYou += b.beans(opponent(s), i);
    }
    if(sumOfHolesMe == 0 || sumOfHolesYou == 0) // add up the beans in both sides and check if either side total to zero cause then its an invalid board and will return -1
    {
        return(-1);
    }
    for(int i = 1; i <= b.holes(); i++) // choose lowest number hole that still has beans in it
    {
        if(b.beans(s, i) > 0)
        {
            return(i);
        }
    }
    return(1);
}

BadPlayer::~BadPlayer() // destructor for bad player
{}

////////////////////

SmartPlayer::SmartPlayer(string name) : Player(name) // constructor is like this because of inheritance
{}

bool SmartPlayer::isInteractive() const // smart player is not interactive
{
    return(false);
}

SmartPlayer::~SmartPlayer() // destructor for smart player
{}

bool SmartPlayer::hasThisSideWon(const Board& b, Side s) const // this functin will check if the side has won yet
{
    int ourTotal = 0;
    int oppositeTotal = 0;
    if(b.beansInPlay(s) == 0 || b.beansInPlay(opponent(s)) == 0) // if one side has no beans in play
    {
        ourTotal = b.beansInPlay(s) + b.beans(s, 0);
        oppositeTotal = b.beansInPlay(opponent(s)) + b.beans(opponent(s), 0); // add up beans in play from both sides and pot
        if(ourTotal > oppositeTotal) // then compare and see if our side has won
        {
            return(true);
        }
        else
        {
            return(false);
        }
    }
    return(false);
}


int SmartPlayer::maximize(const Board& b, Side s, int depthTracker) const // wants to maximize the computers score
{
    int score = -1000000;
    if(hasThisSideWon(b, s) == true) // will check if our side has won
    {
        return(1000); // then will give it a really high score cause this is a good move
    }
    else if(hasThisSideWon(b, opponent(s)) == true) // will check if the other side has won
    {
        return(-1000); // then will give it a really low score cause this is a bad move
    }
    else if(depthTracker == 7) // if we reach a depth then we will calculate the difference between our pot and their pot and return that score
    {
        score = b.beans(s, 0) - b.beans(opponent(s), 0);
        return(score);
    }
    for(int i = 1; i <= b.holes(); i++) // iterate through every hole/move choice
    {
        Side endSide;
        int endHole;
        Board copyOfBoard(b); // make a copy of the board so we can undo the move
        copyOfBoard.sow(opponent(s), i, endSide, endHole); // make the move that we want to make
        if(endSide == s && copyOfBoard.beans(endSide, endHole) == 1)
        {
            if(copyOfBoard.beans(opponent(s), endHole) > 0)
            {
                copyOfBoard.moveToPot(s, endHole, s);
                copyOfBoard.moveToPot(opponent(s), endHole, s);
            }
        }
        score = max(score, minimize(copyOfBoard, s, depthTracker+1)-depthTracker); // choose the score that is higher out of the current score and the score from minimize that will take in a copy of our current board
    }
    return(score);
}

int SmartPlayer::minimize(const Board& b, Side s, int depthTracker) const // this wants to minimize the opponents score
{
    int score = 100000;
    if(hasThisSideWon(b, s) == true) // will check if our side has won
    {
        return(1000); // gives us a high score cause this is a good move
    }
    else if(hasThisSideWon(b, opponent(s)) == true) // will check if the opponent has won
    {
        return(-1000); // gives us a low score cause this is a bad move
    }
    if(depthTracker == 7) // if we reach the depth specified then take the difference between the pots and return that as the score
    {
        score = b.beans(opponent(s), 0) - b.beans(s, 0);
        return(score);
    }
    for(int i = 1; i <= b.holes(); i++) //iterate through every hole and move choice
    {
        Side endSide;
        int endHole;
        Board copyOfBoard(b); // make a copy of the board
        copyOfBoard.sow(s, i, endSide, endHole); // make the move that we want
        if(endSide == s && copyOfBoard.beans(endSide, endHole) == 1) // check to see if a capture is possible
        {
            if(copyOfBoard.beans(opponent(s), endHole) > 0)
            {
                copyOfBoard.moveToPot(s, endHole, s);
                copyOfBoard.moveToPot(opponent(s), endHole, s);
            }
        }
        score = min(score, maximize(copyOfBoard, s, depthTracker+1)+depthTracker); // take the lower score out of the current score and a call to maximize with a copy of the board
    }
    return(score);
}

int SmartPlayer::chooseMove(const Board& b, Side s) const
{
    int sumOfHolesMe = 0;
    for(int i = 1; i <= b.holes(); i++)
    {
        sumOfHolesMe += b.beans(s, i);
    }
    int sumOfHolesYou = 0;
    for(int i = 1; i <= b.holes(); i++)
    {
        sumOfHolesYou += b.beans(opponent(s), i);
    }
    if(sumOfHolesMe == 0 || sumOfHolesYou == 0) // will check to make sure that the current board that was given is valid and if it isnt will return -1
    {
        return(-1);
    }
    int hole = 0;
    int depthTracker = 0;
    int currentMax = 1000000;
    for(int i = 1; i <= b.holes(); i++) // iterate through all of the holes
    {
        if(b.beans(s, i) > 0) // will check to make sure that there are beans in the hole before making that move
        {
            Side endSide;
            int endHole;
            Board copyOfBoard(b); // make a copy of the board
            copyOfBoard.sow(s, i, endSide, endHole); // make the move we want
            if(endSide == s && copyOfBoard.beans(endSide, endHole) == 1) // check to see if a capture is possible
            {
                if(copyOfBoard.beans(opponent(s), endHole) > 0)
                {
                    copyOfBoard.moveToPot(s, endHole, s);
                    copyOfBoard.moveToPot(opponent(s), endHole, s);
                }
            }
            int score = maximize(copyOfBoard, s, depthTracker); // make a call to maximize for the current board we have
            if(score < currentMax) // compare the new score to the current max
            {
                currentMax = score; // reassign currentmax and hole for the best choice so far
                hole = i;
            }
        }
    }
    return(hole); // return best hole choice
}
