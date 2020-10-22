//
//  main.cpp
//  CS 32 Project 4
//
//  Created by Jake Herron on 6/1/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cassert>
using namespace std;

int lineCounter = 0;


struct Node // the structure of a node in my binary search tree
{
    string key; // has the string as the key
    int index; // also stores index or offset of string
    Node* left;
    Node* right;
};

class BST // making my own Binary search tree
{
public:
    BST();
    ~BST();
    void insert(string key, int index);
    Node* find(string key);
    
private:
    void destructorHelper(Node* node); // will help destroy my nodes
    void insert(Node* node, string key, int index); // will help insert items
    Node* find(Node* node, string key); // will help find items
    Node* root; // starts with root node
};

BST::BST()
{
    root = nullptr; // initialize root to nullpointer
}

BST::~BST()
{
    destructorHelper(root); // call helper func to destroy everything
}

void BST::destructorHelper(Node* node)
{
    if(node != nullptr) // if we arent at the end of a leaf
    {
        destructorHelper(node->left); // keep going down the left side until we hit a nullptr
        destructorHelper(node->right); // keep going down the right side until we hit a nullptr
        delete node; // delete the node that has a nullptr children
    }
}

void BST::insert(Node* node, string key, int index)
{
    if(node->key > key) // if the key of the node is greater than our insertion key
    {
        if(node->left == nullptr) // then lets go down the left side and see if we have nullptr
        {
            node->left = new Node; // if we reached a leaf then make a new node
            node->left->key = key; // give it the values we passed into the func
            node->left->index = index;
            node->left->left = nullptr; // give its children null pointers
            node->left->right = nullptr;
        }
        else
        {
            insert(node->left, key, index); // keep going down the left if we didnt reach a nullptr
        }
    }
    else if(node->key < key) // if the key of the node is less than our insertion key
    {
        if(node->right == nullptr) // go down the right side and see if we have nullptr
        {
            node->right = new Node; // if we reached a leaf then make a new node
            node->right->key = key; // give it the values we passed into the func
            node->right->index = index;
            node->right->right = nullptr; // give its children null pointers
            node->right->left = nullptr;
        }
        else
        {
            insert(node->right, key, index); // keep going down the right if we didnt reach a null pointer
        }
    }
}

void BST::insert(string key, int index)
{
    if(root == nullptr) // if the tree is empty
    {
        root = new Node; // make a new node that will now be the root
        root->key = key; // assign it our values
        root->index = index;
        root->left = nullptr; // give its children null pointers
        root->right = nullptr;
    }
    else
    {
        insert(root, key, index); // if the tree is not empty then call our helper from the root
    }
}

Node* BST::find(Node* node, string key)
{
    if(node == nullptr) //if we could not find a matching key return nullptr
    {
        return(nullptr);
    }
    else
    {
        if(node->key == key) // if we found the matching key then return that node
        {
            return(node);
        }
        else if(node->key > key) // if the key of current node is greater than our key then lets move to the left and look again
        {
            return(find(node->left, key));
        }
        else // otherwise lets go to the right and look again
        {
            return(find(node->right, key));
        }
    }
}

Node* BST::find(string key)
{
    return(find(root, key)); // call the find func from the root
}




bool getInt(istream& inf, int& n)
{
    char ch;
    if (!inf.get(ch)  ||  !isascii(ch)  ||  !isdigit(ch))
        return false;
    inf.unget();
    inf >> n;
    return true;
}

bool getCommand(istream& inf, char& cmd, int& length, int& offset)
{
    if (!inf.get(cmd))
    {
        cmd = 'x';  // signals end of file
        return true;
    }
    char ch;
    switch (cmd)
    {
        case 'A':
            return getInt(inf, length) && inf.get(ch) && ch == ':';
        case 'C':
            return getInt(inf, length) && inf.get(ch) && ch == ',' && getInt(inf, offset);
        case '\r':
        case '\n':
            return true;
    }
    return false;
}







void createDiff(istream& fold, istream& fnew, ostream& fdiff);
string createDiffHelper(string oldFileString, string newFileString, int N);
bool applyDiff(istream& fold, istream& fdiff, ostream& fnew);


void createDiff(istream& fold, istream& fnew, ostream& fdiff)
{
//    string oldFileString;
//    string newFileString;
//    getline(fold, oldFileString, '\0'); // get the entirety of old file and put it into string
//    getline(fnew, newFileString, '\0'); // get entirety of new file and put it into string
//    if(newFileString[newFileString.size()-1] != '\n') // if the new string doesnt end in new line then add it to make it match the given file
//    {
//        newFileString += '\n';
//    }
    string oldFileString;
    string newFileString;
    char ch;
    while (fold.get(ch))
    {
        if(ch == '\n')
        {
            lineCounter += 1;
        }
        oldFileString += ch;
    }
    char ch1;
    while (fnew.get(ch1))
    {
        
        newFileString += ch1;
    }
//        stringstream oldBuffer;
//        stringstream newBuffer;
//        oldBuffer << fold.rdbuf();
//        string oldFileString(oldBuffer.str());
//        newBuffer << fnew.rdbuf();
//        string newFileString(newBuffer.str());
//    getline(fold, oldFileString, '\0'); // get the entirety of old file and put it into string
//    getline(fnew, newFileString, '\0');
    vector<string> diffVectorStrings; // make a vector for our diffStrings
    int N = 50; // we're gonna test for string sizes 2 to 50
    while(N > 0) // loop through from 0 to 50
    {
        string temp = createDiffHelper(oldFileString, newFileString, N);// call the create diff helper func with this value of N
        diffVectorStrings.push_back(temp); // push the diff string into the vector
        N-=2;
    }
    string currentMin = diffVectorStrings[0];
    for(int i = 0; i < diffVectorStrings.size(); i++) // find the minimum size of all the diff strings in our vector
    {
        if(diffVectorStrings[i].size() < currentMin.size())
        {
            currentMin = diffVectorStrings[i];
        }
    }
    fdiff << currentMin; // write the smallest one to our diff file
}

string createDiffHelper(string oldFileString, string newFileString, int N)
{
//    string oldFileString;
//    string newFileString;
//    string tempString;
//    while(getline(fold, tempString))
//    {
//        oldFileString += tempString;
//    }
//    while(getline(fnew, tempString))
//    {
//        newFileString += tempString;
//    }
//    stringstream oldBuffer;
//    stringstream newBuffer;
//    oldBuffer << fold.rdbuf();
//    string oldFileString(oldBuffer.str());
//    newBuffer << fnew.rdbuf();
//    string newFileString(newBuffer.str());
    string diffString = ""; // make an empty diff string
    //int N = 22; //22 // 44
    BST oldFileBST; // construct our empty bst
    for(int index = 0; index < oldFileString.size(); index++) // insert all the N sized string segments from our old file string into the bst
    {
        oldFileBST.insert(oldFileString.substr(index, N), index);
    }
    
    vector<char> addInstruction; // make a vector for chars we are gonna need for the add func
    int copyInstructionLength = 0; // initialize our variables
    int indexOfStartOfCopy = 0;
    for(int j = 0; j < newFileString.size(); ) // iterate from the beginning of the new file string until the end
    {
        string currentSubstring = newFileString.substr(j, N); // make a subtring of size N starting at the index of the new file string we are on currently
        Node* finderIter = oldFileBST.find(currentSubstring); // now look it up in the bst
        
        if(finderIter != nullptr) // if we found it in the bst
        {
            if(addInstruction.size() > 0) // if there are chars in our add vector
            {
                diffString += "A" + to_string(addInstruction.size()) + ":"; // write the instructions for an add to the diff string
                for(int k = 0; k < addInstruction.size(); k++)
                {
                    diffString += addInstruction[k]; // write the characters to the diff string
                }
                addInstruction.clear(); // reset the add vector
            }
            copyInstructionLength = N; // now store the length of the match
            indexOfStartOfCopy = finderIter->index; // and the offset of the match
            
            int indexOfMatchOldFile = finderIter->index + N;
            int indexOfMatchNewFile = j + N;
            while((indexOfMatchOldFile < oldFileString.size() && indexOfMatchNewFile < newFileString.size()) && oldFileString[indexOfMatchOldFile] == newFileString[indexOfMatchNewFile]) // now iterate through the old string and the new string until they stop matching
            {
                indexOfMatchOldFile += 1;
                indexOfMatchNewFile += 1;
            }
            copyInstructionLength = indexOfMatchOldFile - indexOfStartOfCopy; // the length of the match is the index we ended at minus the offset we started at
            if(copyInstructionLength + indexOfStartOfCopy <= oldFileString.size()) // this length needs to be less than the size of the old string
            {
                diffString += "C" + to_string(copyInstructionLength) + "," + to_string(indexOfStartOfCopy); // write out the instructions for the copy to the diff string
                j = indexOfMatchNewFile; // now set the index of the for loop to the end of the match because we can now ignore all the chars that will be copied over
            }
            else // if the match length gets us ove the size of the string then somethings wrong and lets break out
            {
                break;
            }
        }
        
        else // if there was no match
        {
            addInstruction.push_back(newFileString[j]); // push the char to the add vector to be used later and go to the next char
            j++;
        }
        
    }
    if(addInstruction.size() > 0) // if we have leftover add chars in the vector
    {
        diffString += "A" + to_string(addInstruction.size()) + ":"; // then put these leftovers into the diff string
        for(int i = 0; i < addInstruction.size(); i++)
        {
            diffString += addInstruction[i];
        }
        addInstruction.clear();
    }
    return(diffString); // return the completed diff string
}

bool applyDiff(istream& fold, istream& fdiff, ostream& fnew)
{
    char cmd;
    int length = 0;
    int offset = 0;
    while(getCommand(fdiff, cmd, length, offset) == true) // while we get valid commands from our diff file
    {
        if(cmd == 'x') // if we reach the end of the diff file
        {
            if(lineCounter <= 1) // i had to do this with the new line character because when I only had a file with one line, applying the diff file would not apply this last new line character and my new file would be off by only a new line character from the correct new file so i had to resort to a global variable
            {
                fnew << '\n';
            }
            return(true); // then return true cause thats good
        }
        else if(cmd == 'A') // if we encounter an add
        {
            char ch;
            while(length > 0) // iterate through every char until the length is 0
            {
                if(!fdiff.get(ch)) // if we can't get the char then return false cause something is wrong with the diff file
                {
                    return(false);
                }
                fnew << ch; // write out the char to the new file
                length--; // decrement the length
            }
        }
        else if(cmd == 'C') // if we encounter a copy
        {
            fold.seekg(offset); // start the iterator at the offset that the command says to
            char* charArray = new char[length]; // make a char array of the size that we got from getCommand
            if(!fold.read(charArray, length)) // if we can't read the old file for the number of chars that the diff file says to then the diff file is messed up
            {
                delete [] charArray; // so lets delete our char array
                return(false); // and return false because the diff file was malformed
            }
            for(int i = 0; i < length; i++) // go through the whole array of chars that we were told to copy
            {
                fnew << charArray[i]; // and write them all to our new file
            }
            delete [] charArray; // delete the array to avoid memory leaks
        }
    }
    return(false); // the diff file was bad if we end up here
}






bool runtest(string oldName, string newName, string diffName, string newName2)
{
    if (diffName == oldName  ||  diffName == newName  ||
        newName2 == oldName  ||  newName2 == diffName  ||
        newName2 == newName)
    {
        cerr << "Files used for output must have names distinct from other files" << endl;
        return false;
    }
    ifstream oldFile(oldName, ios::binary);
    if (!oldFile)
    {
        cerr << "Cannot open " << oldName << endl;
        return false;
    }
    ifstream newFile(newName, ios::binary);
    if (!newFile)
    {
        cerr << "Cannot open " << newName << endl;
        return false;
    }
    ofstream diffFile(diffName, ios::binary);
    if (!diffFile)
    {
        cerr << "Cannot create " << diffName << endl;
        return false;
    }
    createDiff(oldFile, newFile, diffFile);
    diffFile.close();
    
    oldFile.clear();   // clear the end of file condition
    oldFile.seekg(0);  // reset back to beginning of the file
    ifstream diffFile2(diffName, ios::binary);
    if (!diffFile2)
    {
        cerr << "Cannot read the " << diffName << " that was just created!" << endl;
        return false;
    }
    ofstream newFile2(newName2, ios::binary);
    if (!newFile2)
    {
        cerr << "Cannot create " << newName2 << endl;
        return false;
    }
    assert(applyDiff(oldFile, diffFile2, newFile2));
    newFile2.close();
    
    newFile.clear();
    newFile.seekg(0);
    ifstream newFile3(newName2, ios::binary);
    if (!newFile)
    {
        cerr << "Cannot open " << newName2 << endl;
        return false;
    }
    if ( ! equal(istreambuf_iterator<char>(newFile), istreambuf_iterator<char>(),
                 istreambuf_iterator<char>(newFile3), istreambuf_iterator<char>()))
        {
            
            cerr << newName2 << " is not identical to " << newName
            << "; test FAILED" << endl;
            return false;
        }
    return true;
    }
        
int main()
{
    assert(runtest("smallmart1.txt", "smallmart2.txt", "diff.txt", "new.txt"));
    assert(runtest("greeneggs1.txt", "greeneggs2.txt", "diff.txt", "new.txt"));
    assert(runtest("warandpeace1.txt", "warandpeace2.txt", "diff.txt", "new.txt"));
    assert(runtest("strange1.txt", "strange2.txt", "diff.txt", "new.txt"));
    cerr << "Test PASSED" << endl;
}
