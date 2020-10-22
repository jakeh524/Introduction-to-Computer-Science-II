//
//  Game.cpp
//  CS 32 Project 3
//
//  Created by Jake Herron on 5/14/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//

#include "Game.h"
#include "Side.h"
#include <iostream>

Game::Game(const Board& b, Player* south, Player* north) : m_Board(b), m_PlayerSouth(south), m_PlayerNorth(north) // call constructors for everything that we have
{
    m_turn = SOUTH; // south always goes first
}

void Game::display() const
{
    cout << "\t\t\t\t\t\t" << m_PlayerNorth->name() << endl; // display first line - north name
    
    string line2 = "\t\t\t\t";
    for(int i = 1; i <= m_Board.holes(); i++) // add the numbers to line two
    {
        line2 = line2 + to_string(i) + "\t";
    }
    cout << line2 << endl;
    
    string line3 = "\t\t\t\t";
    for(int i = 1; i <= m_Board.holes()-1; i++)
    {
        line3 += "----"; // add the dividers for line 3
    }
    line3 += "-";
    cout << line3 << endl;
    
    string line4 = "\t\t\t\t";
    for(int i = 1; i <= m_Board.holes(); i++)
    {
        line4 += to_string(m_Board.beans(NORTH, i)) + "\t"; // add the beans for the north side to line 4
    }
    cout << line4 << endl;
    
    string line5 = m_PlayerNorth->name() + "'s Pot\t"; // add the name for north pot to line 5
    line5 += to_string(m_Board.beans(NORTH, 0));
    line5 += "\t";
    for(int i = 1; i < m_Board.holes(); i++)
    {
        line5 += "\t "; // add spaces to line 5
    }
    line5 += "\t";
    line5 += to_string(m_Board.beans(SOUTH, 0));
    line5 += " " + m_PlayerSouth->name() + "'s Pot"; // add the name for south pot to line 5
    cout << line5 << endl;
    
    string line6 = "\t\t\t\t";
    for(int i = 1; i <= m_Board.holes(); i++)
    {
        line6 += to_string(m_Board.beans(SOUTH, i)) + "\t"; // add the beans to line 6
    }
    cout << line6 << endl;
    
    string line7 = "\t\t\t\t";
    for(int i = 1; i <= m_Board.holes()-1; i++) // add the spaces for line 7
    {
        line7 += "----";
    }
    line7 += "-";
    cout << line7 << endl;
    
    string line8 = "\t\t\t\t";
    for(int i = 1; i <= m_Board.holes(); i++)
    {
        line8 = line8 + to_string(i) + "\t"; // add the hole numbers to line 8
    }
    cout << line8 << endl;
    
    cout << "\t\t\t\t\t\t" << m_PlayerSouth->name() << endl; // add the south name to line 9
}

void Game::status(bool& over, bool& hasWinner, Side& winner) const
{
    hasWinner = false;
    int northSum = 0;
    for(int i = 1; i <= m_Board.holes(); i++) // add up all the beans in play for north
    {
        northSum += m_Board.beans(NORTH, i);
    }
    int southSum = 0;
    for(int i = 1; i <= m_Board.holes(); i++) // add up all the beans in play for south
    {
        southSum += m_Board.beans(SOUTH, i);
    }
    int northTotal = 0;
    int southTotal = 0;
    if(northSum == 0) // if north is 0 that means that the game is over
    {
        over = true;
        northTotal = m_Board.beans(NORTH, 0); // add up the totals for both sides of beans in play and pot
        southTotal = m_Board.beansInPlay(SOUTH) + m_Board.beans(SOUTH, 0);
        if(northTotal > southTotal) // if north is bigger than south then we have a winner and its north
        {
            hasWinner = true;
            winner = NORTH;
        }
        else if(northTotal < southTotal) // if north is less than south then south wins
        {
            hasWinner = true;
            winner = SOUTH;
        }
    }
    else if(southSum == 0) // if south is 0 that means game over
    {
        over = true;
        southTotal = m_Board.beans(SOUTH, 0); // add up the totals for both sides of beans in play and pot
        northTotal = m_Board.beansInPlay(NORTH) + m_Board.beans(NORTH, 0);
        if(southTotal > northTotal) // if south is gretaer than north then south wins
        {
            hasWinner = true;
            winner = SOUTH;
        }
        else if(southTotal < northTotal) // if south is less than north then north wins
        {
            hasWinner = true;
            winner = NORTH;
        }
    }
    else // if neither sides sum is 0 then its not over
    {
        over = false;
    }
}

bool Game::move()
{
    bool over;
    bool hasWinner;
    Side winner;
    status(over, hasWinner, winner); // check and see if game is over
    if(over == true)
    {
        for(int i = 1; i <= m_Board.holes(); i++) // if it is then move all the beans to their pots
        {
            m_Board.moveToPot(SOUTH, i, SOUTH);
            m_Board.moveToPot(NORTH, i, NORTH);
        }
        return(false);
    }
    
    if(m_turn == SOUTH) // if its souths turn
    {
        bool isTurnOver = false;
        while(isTurnOver == false)
        {
            status(over, hasWinner, winner); // check if game is over
            if(over == true)
            {
                for(int i = 1; i <= m_Board.holes(); i++) // if it is then move beans to pots
                {
                    m_Board.moveToPot(SOUTH, i, SOUTH);
                    m_Board.moveToPot(NORTH, i, NORTH);
                }
            }
            isTurnOver = true;
            int firstMoveHole;
            Side endSide;
            int endHole;
            firstMoveHole = m_PlayerSouth->chooseMove(m_Board, SOUTH); // call choose move for the south player
            if(firstMoveHole == -1) // if its an invalid board then return false for func
            {
                return(false);
            }
            m_Board.sow(SOUTH, firstMoveHole, endSide, endHole);// make the move with the hole that was chosen
            if(endHole == 0) // if we end up in a pot
            {
                isTurnOver = false; // change flag so we go ghrough while loop again and get another turn
                status(over, hasWinner, winner); // check if game is over
                if(over == true)
                {
                    for(int i = 1; i <= m_Board.holes(); i++) // if it is move beans to pots
                    {
                        m_Board.moveToPot(SOUTH, i, SOUTH);
                        m_Board.moveToPot(NORTH, i, NORTH);
                    }
                }
                display(); // display when turn is over
            }
            else if(endSide == m_turn && m_Board.beans(endSide, endHole) == 1) // check and see if there is a capture
            {
                if(m_Board.beans(opponent(endSide), endHole) > 0)
                {
                    m_Board.moveToPot(m_turn, endHole, m_turn); // if there is then execute the capture
                    m_Board.moveToPot(opponent(m_turn), endHole, m_turn);
                    display(); // and then display again
                }
            }
        }
    }
    else if(m_turn == NORTH) // if its norths turn
    {
        bool isTurnOver = false;
        status(over, hasWinner, winner);
        if(over == true)
        {
            for(int i = 1; i <= m_Board.holes(); i++) // check if game is over and if it is then move the beans to pots
            {
                m_Board.moveToPot(SOUTH, i, SOUTH);
                m_Board.moveToPot(NORTH, i, NORTH);
            }
        }
        while(isTurnOver == false)
        {
            isTurnOver = true;
            int firstMoveHole;
            Side endSide;
            int endHole;
            firstMoveHole = m_PlayerNorth->chooseMove(m_Board, NORTH); // call north players choose move func
            if(firstMoveHole == -1) // if the board is invalid then return false
            {
                return(false);
            }
            m_Board.sow(NORTH, firstMoveHole, endSide, endHole); // make the move that we chose
            if(endHole == 0)
            {
                isTurnOver = false; // if we ended up in a pot then change flag so we get another turn
                status(over, hasWinner, winner); // check if game is over
                if(over == true)
                {
                    for(int i = 1; i <= m_Board.holes(); i++) // if it is move everything to the pots
                    {
                        m_Board.moveToPot(SOUTH, i, SOUTH);
                        m_Board.moveToPot(NORTH, i, NORTH);
                    }
                }
                display(); // display game
            }
            else if(endSide == m_turn && m_Board.beans(endSide, endHole) == 1) // check if there is a capture
            {
                if(m_Board.beans(opponent(endSide), endHole) > 0)
                {
                    m_Board.moveToPot(m_turn, endHole, m_turn); // if there is then execute capture
                    m_Board.moveToPot(opponent(m_turn), endHole, m_turn);
                    display(); // display baord
                }
            }
        }
    }
    
    m_turn = opponent(m_turn); // change whoes turn it is
    
    return(true); // return true that we made a move
}

void Game::play()
{
    bool over = false;
    bool hasWinner = false;
    Side winner = SOUTH; // initializing to SOUTH only to get rid of the warning that it may be uninitialized
    if(m_Board.beansInPlay(SOUTH) == 0) // if there are no beans in play for south at the start
    {
        display(); // display board
        for(int i = 1; i < m_Board.holes(); i++) // add all of norths beans to the pot
        {
            m_Board.moveToPot(NORTH, i, NORTH);
        }
        over = true; // change that its over
        display(); // display
    }
    while(over == false) // loop through this
    {
        display(); // display game
        move(); // call move
        status(over, hasWinner, winner); // check status of game
        if(m_PlayerSouth->isInteractive() == false && m_PlayerNorth->isInteractive() == false) // if there both computers then make us press enter every once in a while
        {
            cout << "Press ENTER to continue";
            cin.ignore();
        }
    }
    if(hasWinner == true) // if we found a winner
    {
        display(); // display game
        if(winner == SOUTH) // if south won display message
        {
            cout << m_PlayerSouth->name() << " has won Kalah!" << endl;
        }
        else if(winner == NORTH) // if north won display messgae
        {
            cout << m_PlayerNorth->name() << " has won Kalah!" << endl;
        }
    }
    else // if there is no winner but game is over then we tied
    {
        cout << "The game has resulted in a tie!" << endl;
    }
}

int Game::beans(Side s, int hole) const
{
    if(hole < 0 || hole > m_Board.holes()) // check if hole is valid
    {
        return(-1);
    }
    return(m_Board.beans(s, hole)); // call boards bean func
}
