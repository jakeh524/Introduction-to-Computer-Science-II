//
//  Sequence.cpp
//  CS 32 Project 2
//
//  Created by Jake Herron on 4/19/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//

#include "Sequence.h"

Sequence::Sequence() //constructor
{
    m_size = 0; // set init size to 0
    head = new Node; // create a dummy node
    head->next = head; // point next and prev to the dummy
    head->prev = head;
}

Sequence::~Sequence() // destructor
{
    while(head->next != head) // loop through the linked list
    {
        Node* p = head->prev; // reassign all the pointers around each item
        p->prev->next = head;
        head->prev = p->prev;
        delete p; // then delete these pointers
    }
    delete head; // finallly delete dummy
}

Sequence::Sequence(const Sequence& other) // copy constructor
{
    m_size = 0; // init size to 0
    head = new Node; // allocate space for the copy
    head->next = head; // copy over the next and prev pointers to the head
    head->prev = head;
    int counter = 0;
    while(counter != other.size()) // loop through the list
    {
        ItemType x;
        other.get(counter, x);
        insert(counter, x); // copy and insert each element from other to this
        counter++;
    }
}

Sequence& Sequence::operator=(const Sequence& rhs) // assignment operator
{
    if (this != &rhs) //  check if they are already equivalent
    {
        Sequence temp(rhs); // use the copy constructor
        swap(temp); // then use the swap function
    }
    return(*this); // return a dereferene to this
}


bool Sequence::empty() const
{
    if(m_size == 0) // check if the list is empty by checking the size
    {
        return true;
    }
    return false;
}

int Sequence::size() const
{
    return(m_size); // return the size data member
}

int Sequence::insert(int pos, const ItemType& value)
{
    if(pos >= 0 && pos <= size()) // check that pos is in bounds
    {
        Node* insertion = new Node; // allocate space for the insertion
        insertion->data = value; // assign the value
        int counter = 0;
        Node* p = head->next; // create your pointer to look through the list
        while(counter != pos) // loop through the list until you get to the desired pos
        {
            p = p->next;
            counter++;
        }
        insertion->next = p; // reassign the pointers around the insertion to properly insert it
        insertion->prev = p->prev;
        p->prev->next = insertion;
        p->prev = insertion;
        m_size += 1; // increment size
        return(pos); // return pos that it was inserted
    }
    return(-1); // return -1 if it didnt work
}

int Sequence::insert(const ItemType& value)
{
    int pos = size(); // start the pos at size
    int counter = 0;
    Node* p = head->next; // create the pointer that will be used to look through list
    while(p != head && value > p->data) // loop through until we find the correct pos or until the end of the list
    {
        p = p->next;
        counter++;
    }
    pos = counter; // pos will be gotten from the counter
    int returnValue = this->insert(pos, value); // use the insert function to properly insert it
    return(returnValue); // return where it was inserted
}

bool Sequence::erase(int pos)
{
    if(pos >= 0 && pos < size()) // check that pos is in bounds
    {
        int counter = 0;
        Node* p = head->next; // create the pointer used to look through list
        while(p != head && counter != pos) // loop through list until we get to the right pos
        {
            p = p->next;
            counter++;
        }
        p->prev->next = p->next; // once we find the right pos rearrange the pointers
        p->next->prev = p->prev;
        m_size -= 1; // then deduct the size
        delete p; // then delete the object that we want to erase
        return(true);
    }
    return(false);
}

int Sequence::remove(const ItemType& value)
{
    int removeCounter = 0; // start a counter that we will return later
    int posCounter = 0;
    Node* p = head->next; // create the pointer we will use to look through list
    while(p != head) // loop through the whole list
    {
        if(p->data == value) // check if we find something we want to remove
        {
            this->erase(posCounter); // call erase function to get rid of it properly
            removeCounter++; // increment our counter
        }
        p = p->next;
        posCounter++;
    }
    return(removeCounter); // return how many times it was removed
}

bool Sequence::get(int pos, ItemType& value) const
{
    if (pos >= 0 && pos < size()) // check if pos is in bounds
    {
        int counter = 0;
        Node* p = head->next; // create the pointer to look through list
        while(p != head && pos != counter) // loop through list until we get the desired pos
        {
            p = p->next;
            counter++;
        }
        value = p->data; // assign value the contents of the position once we get there
        return(true);
    }
    return(false);
}

bool Sequence::set(int pos, const ItemType& value)
{
    if (pos >= 0 && pos < size()) // check if pos is within bounds
    {
        int counter = -1;
        Node* p = head; // create the pointer to look through the list
        while(p != head && counter != pos) // loop through list until we get to the pos
        {
            p = p->next;
            counter++;
        }
        p->data = value; // assign the data member the value we want
        return(true);
    }
    return(false);
}

int Sequence::find(const ItemType& value) const
{
    int p = -1; // default case for p
    int counter = 0;
    Node* ptr = head->next; // create the pointer we will use to look at list
    if (size() == 1 && head->data == value) // check if the list is only 1 long
    {
        return(0);
    }
    while(ptr != head) // loop through the list
    {
        if(ptr->data == value) // check if we found the data
        {
            p = counter;
            return(p); // return the pos
        }
        ptr = ptr->next;
        counter++;
    }
    return(p); // return the found pos
}

void Sequence::swap(Sequence& other)
{
    int temporarySize = this->m_size; // create a temp size
    Node* temporary = this->head; // create a temp head
    this->m_size = other.m_size; // exchange the sizes
    this->head = other.head; // exchange the heads
    other.m_size = temporarySize; // exchange the sizes
    other.head = temporary; // exchange the heads
}


int subsequence(const Sequence& seq1, const Sequence& seq2)
{
    ItemType x;
    ItemType y;
    int counter = 0;
    bool flag = false; // flag to check if we have found a match
    while(counter < seq1.size()) // loop through seq1
    {
        seq2.get(0, y); // get the first item we want to look for
        seq1.get(counter, x); // get each item from seq1
        if(x == y) // check if the first item of seq2 and each item of seq1 match
        {
            int firstPos = counter; // the firstPos in seq1 that matches will be counter and we will return it later
            int startingIndex = firstPos; // now make another variable that we can increment
            int counter2 = 0; // make a counter used to loop through seq2
            while (counter2 < seq2.size()) // loop through seq1
            {
                flag = true; // change flag to show that we are on the right track
                seq1.get(startingIndex, x); // start storing the subsequent values after the first match
                seq2.get(counter2, y);
                startingIndex++; // increment through both sequences
                counter2++;
                if (x != y) // if they stop being equal that means its not a match
                {
                    flag = false; // thus we change the flag back
                    break; // and then we go back to the start of the loop
                }
            }
            if(flag == true) // if we made it out of the loop with complete matches then proceed
            {
                return(firstPos); // return the first position that the match started from before
            }
        }
        counter++; // if we found a match and it turns out it was fake then lets increment counter and keep going through seq1 until the end
    }
    return(-1); // return -1 if we never found a match
}


void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result)
{
    Sequence tempResult(result); // use a copy constructor to avoid problems from aliasing
    while(tempResult.empty() == false) // loop through the tempResult and erase every item
    {
        tempResult.erase(0);
    }
    int counter = 0;
    int tempResultCounter = 0;
    ItemType data1;
    ItemType data2;
    while(counter < seq1.size() && counter < seq2.size()) // loop through the sequences until we reach the end of one of them
    {
        seq1.get(counter, data1); // collect each item from both sequences
        seq2.get(counter, data2);
        tempResult.insert(tempResultCounter, data1); // insert them into tempResult
        tempResult.insert(tempResultCounter+1, data2);
        tempResultCounter += 2; // increment this by two because we inserted two items
        counter++; // increment this by one because this belongs to each sequence
    }
    if(seq1.size() < seq2.size()) // if theres more of seq2 left proceed
    {
        while(counter < seq2.size()) // loop through the rest of seq2
        {
            seq2.get(counter, data2); // get each item and then insert it into tempResult
            tempResult.insert(tempResultCounter, data2);
            tempResultCounter++;
            counter++;
        }
    }
    else if (seq1.size() > seq2.size()) // if theres more of seq1 left proceed
    {
        while(counter < seq1.size()) // loop through the rest of seq1
        {
            seq1.get(counter, data1); // get each item and tehn insert it into the tempResult
            tempResult.insert(tempResultCounter, data1);
            tempResultCounter++;
            counter++;
        }
    }
    result = tempResult; // now use our assignment operator to assign the tempResult to the real result that we wanted to change all along
}
