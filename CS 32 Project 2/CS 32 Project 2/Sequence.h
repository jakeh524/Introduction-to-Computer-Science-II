//
//  Sequence.h
//  CS 32 Project 2
//
//  Created by Jake Herron on 4/19/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//

#ifndef Sequence_h
#define Sequence_h
#include <string>
using ItemType = std::string;

class Sequence
{
public:
    Sequence(); // constructor
    ~Sequence(); // destructor
    Sequence(const Sequence& other); // copy constructor
    Sequence& operator=(const Sequence& rhs); // assignment operator
    bool empty() const;
    int size() const;
    int insert(int pos, const ItemType& value);
    int insert(const ItemType& value);
    bool erase(int pos);
    int remove(const ItemType& value);
    bool get(int pos, ItemType& value) const;
    bool set(int pos, const ItemType& value);
    int find(const ItemType& value) const;
    void swap(Sequence& other);
    
private:
    struct Node
    {
        ItemType data;
        Node* next;
        Node* prev;
    };
    Node* head;
    int m_size;
};

int subsequence(const Sequence& seq1, const Sequence& seq2);
void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result);

#endif /* Sequence_h */
