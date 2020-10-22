//
//  eval.cpp
//  CS 32 HW 2
//
//  Created by Jake Herron on 5/1/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//
#include <iostream>
#include <string>
#include <cassert>
#include <stack>
using namespace std;

string conversion(string infix, string& postfix);
string removeSpaces(string infix);
bool isValidInfix(string infix);


int evaluate(string infix, string& postfix, bool& result)
{
    string newInfix = removeSpaces(infix);
    if (isValidInfix(newInfix) == true)
    {
        postfix = conversion(infix, postfix);
        stack<char> operandStack;
        for(int i = 0; i < postfix.size(); i++)
        {
            if(postfix[i] == 'T' || postfix[i] == 'F')
            {
                operandStack.push(postfix[i]);
            }
            else if(postfix[i] == '!')
            {
                if(operandStack.top() == 'F')
                {
                    operandStack.pop();
                    operandStack.push('T');
                }
                else if(operandStack.top() == 'T')
                {
                    operandStack.pop();
                    operandStack.push('F');
                }
            }
            else
            {
                char operand2 = operandStack.top();
                operandStack.pop();
                char operand1 = operandStack.top();
                operandStack.pop();
                char replacementOperand = 'A';
                if(postfix[i] == '&')
                {
                    if(operand1 == 'T' && operand2 == 'T')
                    {
                        replacementOperand = 'T';
                    }
                    else
                    {
                        replacementOperand = 'F';
                    }
                }
                else if(postfix[i] == '^')
                {
                    if((operand1 == 'T' && operand2 == 'F') || (operand1 == 'F' && operand2 == 'T'))
                    {
                        replacementOperand = 'T';
                    }
                    else
                    {
                        replacementOperand = 'F';
                    }
                }
                operandStack.push(replacementOperand);
            }
        }
        char last = operandStack.top();
        if(last == 'T')
        {
            result = true;
            return(0);
        }
        else if(last == 'F')
        {
            result = false;
            return(0);
        }
    }
    return(1);
    
}
// Evaluates a boolean expression
//   If infix is a syntactically valid infix boolean expression,
//   then set postfix to the postfix form of that expression, set
//   result to the value of the expression, and return zero.  If
//   infix is not a syntactically valid expression, return 1; in
//   that case, postfix may or may not be changed, but result must
//   be unchanged.

string conversion(string infix, string& postfix)
{
    postfix = "";
    stack<char> operatorStack;
    for (int i = 0; i < infix.size(); i++)
    {
        char ch = infix[i];
        switch(ch)
        {
            case 'T':
            case 'F':
                postfix += ch;
                break;
            case '(':
                operatorStack.push(ch);
                break;
            case ')':
                while(operatorStack.top() != '(')
                {
                    postfix += operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.pop();
                break;
            case '!':
                while(operatorStack.empty()==false && operatorStack.top() != '(' && ch >= operatorStack.top())
                {
                    postfix += operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.push(ch);
                break;
            case '&':
                while(operatorStack.empty()==false && operatorStack.top() != '(' && ch >= operatorStack.top())
                {
                    postfix += operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.push(ch);
                break;
            case '^':
                while(operatorStack.empty()==false && operatorStack.top() != '(' && ch >= operatorStack.top())
                {
                    postfix += operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.push(ch);
                break;
        }
    }
    while(operatorStack.empty() == false)
    {
        postfix += operatorStack.top();
        operatorStack.pop();
    }
    return(postfix);
}

string removeSpaces(string infix)
{
    string temp = "";
    for(int i = 0; i < infix.size(); i++)
    {
        if(infix[i] != ' ')
        {
            temp += infix[i];
        }
    }
    return(temp);
}

bool isValidInfix(string infix)
{
    int openParenthesesCounter = 0;
    int closedParenthesesCounter = 0;
    if(infix == "")
    {
        return(false);
    }
    if(infix[infix.size()-1] == '^' || infix[infix.size()-1] == '&' || infix[infix.size()-1] == '!')
    {
        return(false);
    }
    if(infix[0] == '^' || infix[0] == '&')
    {
        return(false);
    }
    for(int i = 0; i < infix.size(); i++)
    {
        char currentChar = infix[i];
        if(currentChar != 'T' && currentChar != 'F' && currentChar != '!' && currentChar != '&' && currentChar != '^' && currentChar != '(' && currentChar != ')')
        {
            return(false);
        }
        if(currentChar == 'T' || currentChar == 'F')
        {
            if(i < infix.size()-1 && (infix[i+1] == 'T' || infix[i+1] == 'F'))
            {
                return(false);
            }
        }
        if(currentChar == '(')
        {
            openParenthesesCounter += 1;
            if(i < infix.size()-1 && (infix[i+1] != '(' && infix[i+1] != 'T' && infix[i+1] != 'F' && infix[i+1] != '!'))
            {
                return(false);
            }
            if(i != 0 && (infix[i-1] != '^' && infix[i-1] != '&' && infix[i-1] != '!' && infix[i-1] != '('))
            {
                return(false);
            }
        }
        if(currentChar == ')')
        {
            closedParenthesesCounter += 1;
        }
        if(currentChar == '!')
        {
            if(i < infix.size()-1 && (infix[i+1] != 'T' && infix[i+1] != 'F' && infix[i+1] != '!' && infix[i+1] != '('))
            {
                return(false);
            }
        }
        if(currentChar == '^' || currentChar == '&')
        {
            if(i < infix.size()-1 && (infix[i+1] != '(' && infix[i+1] != '!' && infix[i+1] != 'T' && infix[i+1] != 'F'))
            {
                return(false);
            }
            if(i > 0 && (infix[i-1] != 'T' && infix[i-1] != 'F' && infix[i-1] != ')'))
            {
                return(false);
            }
        }
    }
    if(openParenthesesCounter != closedParenthesesCounter)
    {
        return(false);
    }
    return(true);
}






int main()
{
    string pf;
    bool answer;
    assert(evaluate("T^ F", pf, answer) == 0  &&  pf == "TF^"  &&  answer);
    assert(evaluate("T^", pf, answer) == 1);
    assert(evaluate("F F", pf, answer) == 1);
    assert(evaluate("TF", pf, answer) == 1);
    assert(evaluate("()", pf, answer) == 1);
    assert(evaluate("()T", pf, answer) == 1);
    assert(evaluate("T(F^T)", pf, answer) == 1);
    assert(evaluate("T(&T)", pf, answer) == 1);
    assert(evaluate("(T&(F^F)", pf, answer) == 1);
    assert(evaluate("T|F", pf, answer) == 1);
    assert(evaluate("", pf, answer) == 1);
    assert(evaluate("F  ^  !F & (T&F) ", pf, answer) == 0 &&  pf == "FF!TF&&^"  &&  !answer);
    assert(evaluate(" F  ", pf, answer) == 0 &&  pf == "F"  &&  !answer);
    assert(evaluate("((T))", pf, answer) == 0 &&  pf == "T"  &&  answer);
    cout << "Passed all tests" << endl;
}
