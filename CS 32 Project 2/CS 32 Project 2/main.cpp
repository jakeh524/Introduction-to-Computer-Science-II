//
//  main.cpp
//  CS 32 Project 2
//
//  Created by Jake Herron on 4/19/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//

#include "Sequence.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

void test()
{
//    assert(s.empty() == true);
//    assert(s.insert(0, 1) == 0);
//    assert(s.insert(0, 0) == 0);
//    assert(s.size() == 2);
//    ItemType x = 999;
//    assert(s.get(0, x)  &&  x == 0);
//    assert(s.get(1, x)  &&  x == 1);
//    assert(s.insert(2) == 2);
//    assert(s.get(2, x) && x == 2);
//    assert(s.erase(1) == true);
//    assert(s.get(1, x) && x == 2);
//    assert(s.insert(1) == 1);
//    assert(s.insert(3) == 3);
//    assert(s.insert(3) == 3);
//    assert(s.remove(4) == 0);
//    assert(s.remove(0) == 1);
//    assert(s.remove(3) == 2);
//    assert(s.get(0, x) && x == 1);
//    assert(s.find(2) == 1);
    
}

int main()
{
    Sequence s1;
    Sequence s2;
    
    s1.insert(0, 6);
    s1.insert(0, 5);
    s1.insert(0, 4);
    s1.insert(0, 3);
    s1.insert(0, 2);
    s1.insert(0, 1);
    s1.insert(0, 0);
    s2.insert(0, 4);
    s2.insert(0, 3);
    s2.insert(0, 2);
    
//    s2.insert(0, 6);
//    s1.insert(0, 5);
//    s1.insert(0, 3);
//    s1.insert(0, 1);
//    s2.insert(0, 4);
//    s2.insert(0, 2);
//    s2.insert(0, 0);
//    Sequence result;
//    result.insert(0, 0);
//    result.insert(0, 0);
//    result.insert(0, 0);
//    result.insert(0, 0);
//    result.insert(0, 0);
//    result.insert(0, 0);
//    result.insert(0, 0);
//    result.insert(0, 0);
//    result.insert(0, 0);
//    result.insert(0, 0);

    assert(subsequence(s1, s2) == 2);
    //ItemType x;
//    for(int i = 0; i < result.size(); i++)
//    {
//        result.get(i, x);
//        cout << x << endl;
//    }
//    Sequence alwaysEmpty;
//    Sequence oneItem;
//    assert(oneItem.insert("a") == 0);
//    string temp;
//
//    // Empty Sequence test cases
//    assert(alwaysEmpty.empty());                // empty() is true
//    assert(alwaysEmpty.size() == 0);            // size is 0
//    assert(alwaysEmpty.erase(0) == false);      // cannot erase
//    assert(alwaysEmpty.remove("blah") == 0);    // cannot remove
//    assert(alwaysEmpty.get(0, temp) == false);  // can't get
//    assert(alwaysEmpty.set(0, "blah") == false);// can't set
//    assert(alwaysEmpty.find("blah") == -1);     // can't find
//
//    // do the same with assignment operator
//    Sequence test;
//    test = alwaysEmpty;
//    assert(test.empty());                // empty() is true
//    assert(test.size() == 0);            // size is 0
//    assert(test.erase(0) == false);      // cannot erase
//    assert(test.remove("blah") == 0);    // cannot remove
//    assert(test.get(0, temp) == false);  // can't get
//    assert(test.set(0, "blah") == false);// can't set
//    assert(test.find("blah") == -1);     // can't find
////
////    // do the same with copy constructor
//    Sequence test2 = alwaysEmpty;
//    assert(test2.empty());                // empty() is true
//    assert(test2.size() == 0);            // size is 0
//    assert(test2.erase(0) == false);      // cannot erase
//    assert(test2.remove("blah") == 0);    // cannot remove
//    assert(test2.get(0, temp) == false);  // can't get
//    assert(test2.set(0, "blah") == false);// can't set
//    assert(test2.find("blah") == -1);     // can't find
////
////    // One Item Sequence test cases
//    assert(!oneItem.empty());               // empty() is false
//    assert(oneItem.size() == 1);            // size is 1
//    assert(oneItem.erase(0) == true);       // can erase
//    assert(oneItem.size() == 0);
//    assert(oneItem.insert("a") == 0);
//    assert(oneItem.size() == 1);
//    assert(oneItem.remove("a") == 1);       // remove "a"
//    assert(oneItem.size() == 0);
//    assert(oneItem.insert("a") == 0);
//    assert(oneItem.size() == 1);
//    assert(oneItem.get(0, temp) == true);   // can get
//    assert(temp == "a");                    // get works
//    assert(oneItem.set(0, "blah") == true); // can set
//    assert(oneItem.find("blah") == 0);      // can find
//
//    assert(oneItem.size() == 1);
////
////    // do the same with assignment operator
//    Sequence test3;
//    test3 = oneItem;
//    assert(!test3.empty());               // empty() is false
//    assert(test3.size() == 1);            // size is 1
//    assert(test3.erase(0) == true);       // can erase
//    assert(test3.insert("a") == 0);
//    assert(test3.remove("a") == 1);       // remove "a"
//    assert(test3.insert("a") == 0);
//    assert(test3.get(0, temp) == true);   // can get
//    assert(temp == "a");                  // get works
//    assert(test3.set(0, "blah") == true); // can set
//    assert(test3.find("blah") == 0);      // can find
////
////    // do the same with copy constructor
//    Sequence test4 = oneItem;
//    assert(!test4.empty());               // empty() is false
//    assert(test4.size() == 1);            // size is 1
//    assert(test4.erase(0) == true);       // can erase
//    assert(test4.insert("a") == 0);
//    assert(test4.remove("a") == 1);       // remove "a"
//    assert(test4.insert("a") == 0);
//    assert(test4.get(0, temp) == true);   // can get
//    assert(temp == "a");                  // get works
//    assert(test4.set(0, "blah") == true); // can set
//    assert(test4.find("blah") == 0);      // can find
////
////
////    // Test swap between 2 empty sequences
//    test.swap(test2);
//    assert(test.empty());                // empty() is true
//    assert(test.size() == 0);            // size is 0
//    assert(test.erase(0) == false);      // cannot erase
//    assert(test.remove("blah") == 0);    // cannot remove
//    assert(test.get(0, temp) == false);  // can't get
//    assert(test.set(0, "blah") == false);// can't set
//    assert(test.find("blah") == -1);     // can't find
//    assert(test2.empty());                // empty() is true
//    assert(test2.size() == 0);            // size is 0
//    assert(test2.erase(0) == false);      // cannot erase
//    assert(test2.remove("blah") == 0);    // cannot remove
//    assert(test2.get(0, temp) == false);  // can't get
//    assert(test2.set(0, "blah") == false);// can't set
//    assert(test2.find("blah") == -1);     // can't find
////
////    // Test swap between 2 one-item sequences
//    test3.swap(test4);
//    assert(!test3.empty());               // empty() is false
//    assert(test3.size() == 1);            // size is 1
//    assert(test3.erase(0) == true);       // can erase
//    assert(test3.insert("a") == 0);
//    assert(test3.remove("a") == 1);       // remove "a"
//    assert(test3.insert("a") == 0);
//    assert(test3.get(0, temp) == true);   // can get
//    assert(temp == "a");                  // get works
//    assert(test3.set(0, "blah") == true); // can set
//    assert(test3.find("blah") == 0);      // can find
////
//    assert(!test4.empty());               // empty() is false
//    assert(test4.size() == 1);            // size is 1
//    assert(test4.erase(0) == true);       // can erase
//    assert(test4.insert("a") == 0);
//    assert(test4.remove("a") == 1);       // remove "a"
//    assert(test4.insert("a") == 0);
//    assert(test4.get(0, temp) == true);   // can get
//    assert(temp == "a");                  // get works
//    assert(test4.set(0, "blah") == true); // can set
//    assert(test4.find("blah") == 0);      // can find
////
////    // Test swap between empty and one-item sequences
//    test.swap(test3);
//    assert(test3.empty());                // empty() is true
//    assert(test3.size() == 0);            // size is 0
//    assert(test3.erase(0) == false);      // cannot erase
//    assert(test3.remove("blah") == 0);    // cannot remove
//    assert(test3.get(0, temp) == false);  // can't get
//    assert(test3.set(0, "blah") == false);// can't set
//    assert(test3.find("blah") == -1);     // can't find
//
//    assert(!test.empty());               // empty() is false
//    assert(test.size() == 1);            // size is 1
//    assert(test.erase(0) == true);       // can erase
//    assert(test.insert("a") == 0);
//    assert(test.remove("a") == 1);       // remove "a"
//    assert(test.insert("a") == 0);
//    assert(test.get(0, temp) == true);   // can get
//    assert(temp == "a");                  // get works
//    assert(test.set(0, "blah") == true); // can set
//    assert(test.find("blah") == 0);      // can find
////
////    // multi-element list
//    Sequence testSeq;
//    testSeq.insert("a"); testSeq.insert("b"); testSeq.insert("c");  testSeq.insert("d");
//
//    assert(!testSeq.empty());           // not empty
//    assert(testSeq.size() == 4);        // size
////
////    // test insert w/ pos
//    assert(testSeq.insert(-1, "a") == -1);  // out of bounds
//    assert(testSeq.insert(10, "a") == -1);  // out of bounds
//    assert(testSeq.insert(0, "a") == 0);    // add at beginning
//    assert(testSeq.insert(5, "f") == 5);    // add at end
//    assert(testSeq.insert(5, "e") == 5);    // add in middle
////
////    // test insert w/o pos
//    assert(testSeq.insert("a") == 0);   // dupe values take 1st index
//    assert(testSeq.insert("b") == 3);
//    assert(testSeq.insert("g") == 9);
////
////
////    // test erase
//    assert(testSeq.erase(-1) == false); // out of bounds
//    assert(testSeq.erase(20) == false); // out of bounds
//    assert(testSeq.erase(0) == true);   // erase first element
//    assert(testSeq.erase(8) == true);    // erase last element
//    assert(testSeq.erase(4) == true);    // erase middle element
////
////
////    // test remove
//    assert(testSeq.remove("z") == 0);   // no z's in seq
//    assert(testSeq.remove("b") == 2);   // 2 b's removed
//    assert(testSeq.size() == 5);
//
////    // test get
//    temp = "";
//    assert(testSeq.get(-1, temp) == false); // out of bounds
//    assert(temp == "");
//    assert(testSeq.get(15, temp) == false); // out of bounds
//    assert(temp == "");
//    assert(testSeq.get(2, temp) == true);
//    assert(temp == "b");
//    assert(testSeq.get(0, temp) == true);
//    assert(temp == "a");
//    assert(testSeq.get(4, temp) == true);
//    assert(temp == "f");
////
////    // test set
//    assert(testSeq.set(-1, "a") == false);  // out of bounds
//    assert(testSeq.set(10, "a") == false);  // out of bounds
//    assert(testSeq.set(1, "b") == true);
//    assert(testSeq.set(4, "h") == true);
////
////
////    // test find
//
////    assert(testSeq.find("z") == -1);     // no z's
////    assert(testSeq.find("a") == 0);     // first element
////    assert(testSeq.find("h") == 4);     // last element
////    assert(testSeq.find("b") == 1);     // middle element
////
////    // Assignment Operator with itself
//    alwaysEmpty = alwaysEmpty;
//    assert(alwaysEmpty.empty());                // empty() is true
//    assert(alwaysEmpty.size() == 0);            // size is 0
//    assert(alwaysEmpty.erase(0) == false);      // cannot erase
//    assert(alwaysEmpty.remove("blah") == 0);    // cannot remove
//    assert(alwaysEmpty.get(0, temp) == false);  // can't get
//    assert(alwaysEmpty.set(0, "blah") == false);// can't set
//    assert(alwaysEmpty.find("blah") == -1);     // can't find
//
//    oneItem = oneItem;
//    assert(!oneItem.empty());               // empty() is false
//    assert(oneItem.size() == 1);            // size is 1
//    assert(oneItem.erase(0) == true);       // can erase
//    assert(oneItem.size() == 0);
//    assert(oneItem.insert("a") == 0);
//    assert(oneItem.size() == 1);
//    assert(oneItem.remove("a") == 1);       // remove "a"
//    assert(oneItem.size() == 0);
//    assert(oneItem.insert("a") == 0);
//    assert(oneItem.size() == 1);
//    assert(oneItem.get(0, temp) == true);   // can get
//    assert(temp == "a");                    // get works
//    assert(oneItem.set(0, "blah") == true); // can set
//    assert(oneItem.find("blah") == 0);      // can find
//    assert(oneItem.size() == 1);
//
//    testSeq = testSeq;
//    assert(!testSeq.empty());           // not empty
//    assert(testSeq.size() == 5);        // size
////
////    // More Assignment Operator
//    Sequence aoTester;
//    aoTester = alwaysEmpty;     // use on empty
//    assert(aoTester.empty());
//    assert(aoTester.size() == 0);
//    aoTester = oneItem;         // use on one item
//    assert(!aoTester.empty());
//    assert(aoTester.size() == 1);
//    aoTester = testSeq;         // use on multi item
//    assert(!aoTester.empty());
//    assert(aoTester.size() == 5);
////
////    // Testing swap
//    Sequence sTester = testSeq;
//
//    sTester.swap(alwaysEmpty);  // use on empty
//    assert(sTester.size() == 0);
//    assert(sTester.empty());
//    assert(alwaysEmpty.size() == 5);
//    assert(!alwaysEmpty.empty());
//
//    sTester.swap(alwaysEmpty);
//
//    sTester.swap(oneItem);      // use on one item
//    assert(sTester.size() == 1);
//    assert(!sTester.empty());
//    assert(oneItem.size() == 5);
//    assert(!oneItem.empty());
//
//    sTester.swap(oneItem);
//
//    sTester = oneItem;
//    sTester.swap(testSeq);      // use on multi item
//    assert(sTester.size() == 5);
//    assert(!sTester.empty());
//    assert(testSeq.size() == 1);
//    assert(!testSeq.empty());
//
//    sTester.swap(testSeq);
//
//    // Swap with itself
//    alwaysEmpty.swap(alwaysEmpty);
//    assert(alwaysEmpty.size() == 0);
//    assert(alwaysEmpty.empty());
//
//
//    oneItem.swap(oneItem);
//    assert(oneItem.size() == 1);
//    assert(!oneItem.empty());
//
//
//    testSeq.swap(testSeq);
//    assert(testSeq.size() == 5);
//    assert(!testSeq.empty());
//
//
//    // test subsequence
//    Sequence noMatch; noMatch.insert("f"); noMatch.insert("q"); noMatch.insert("j");
//    assert(subsequence(testSeq, noMatch) == -1); // no match
//    Sequence almostMatch; almostMatch.insert("b"); almostMatch.insert("d"); almostMatch.insert("f");
//    assert(subsequence(testSeq, almostMatch) == -1); // no match
//    Sequence match; match.insert("b"); match.insert("d"); match.insert("e");
//    //assert(subsequence(testSeq, match) == 1);   // match starting at index 1
//    testSeq.insert("h");
//    Sequence multimatch; multimatch.insert("h");
//    assert(subsequence(testSeq, multimatch) == 4);  // multiple matches, picks first index
//    assert(subsequence(testSeq, testSeq) == 0);    // same sequence, full match
//
//    // empty always returns -1 for subsequence
//    assert(subsequence(testSeq, alwaysEmpty) == -1);
//    assert(subsequence(alwaysEmpty, alwaysEmpty) == -1);
//
//    // test interleave
//    Sequence result;
//
//    // result is empty
//    interleave(testSeq, alwaysEmpty, result);   // interleaving with empty
//
//    assert(result.size() == 6);
//
//    interleave(alwaysEmpty, testSeq, result);   // result works even if already occupied
//
//    assert(result.size() == 6);
//
//    Sequence alwaysEmpty2 = alwaysEmpty;
//    interleave(alwaysEmpty, alwaysEmpty2, result);  // test interleave w/ 2 empty sequences
//    assert(result.size() == 0);
//
//    interleave(alwaysEmpty, alwaysEmpty, result);   // seq1 == seq2 == empty
//    assert(result.size() == 0);
//
//    interleave(alwaysEmpty, alwaysEmpty, alwaysEmpty);   // seq1 == seq2 == result
//    assert(alwaysEmpty.size() == 0);
//
//    Sequence oneItem2 = oneItem;
//    interleave(oneItem, oneItem2, result);  // test interleave w/ 2 one item sequences
//    assert(result.size() == 2);
//
//    interleave(oneItem, oneItem, result);   // seq1 == seq2 == one item
//    assert(result.size() == 2);
//
//    interleave(oneItem2, oneItem2, oneItem2);   // seq1 == seq2 == result
//    assert(oneItem2.size() == 2);
//
//    interleave(testSeq, testSeq, result);   // works on multi item sequences
//    assert(result.size() == 12);
//
//    // interleave works even if result is seq1/seq2
//    Sequence testSeqCopy = testSeq;
//    Sequence testSeqCopy2 = testSeq;
//    interleave(oneItem, testSeqCopy, testSeqCopy);
//    assert(testSeqCopy.size() == 7);
//
//
//    interleave(testSeqCopy2, oneItem, testSeqCopy2);
//    assert(testSeqCopy2.size() == 7);
//
//
//    interleave(testSeqCopy, testSeqCopy, testSeqCopy);   // works on multi item sequences
//
//    assert(testSeqCopy.size() == 14);
    cout << "Passed all tests" << endl;
    return(0);
}
