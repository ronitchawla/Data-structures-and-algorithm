//
//  main.cpp
//  implement queue,using stack
//
//  Created by Ronit Chawla on 2018-10-13.
//  Copyright © 2018 Ronit Chawla. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Stack_base {
public:
    Stack_base(){}
    // C++ base classes should always have a virtual destructor (so that
    // inheriting classes can, if they need to, override it and implement
    // their own destructor)
    virtual ~Stack_base() { }
    
    // Pre-condition:
    //    none
    // Post-condition:
    //    returns true if this stack is empty, and false
    //    otherwise
    // Constraints:
    //    O(1) worst-case running time
    virtual bool is_empty() const = 0;
    
    // Pre-condition:
    //    none
    // Post-condition:
    //    puts x on top of the stack (elements already on stack are
    //    unchanged)
    // Constraints:
    //    O(1) worst-case running time
    virtual void push(int x) = 0;
    
    // Pre-condition:
    //    this stack is not empty
    // Post-condition:
    //    removes and returns the top element of this stack
    // Constraints:
    //    O(1) worst-case running time
    virtual int pop() = 0;
    
    // Pre-condition:
    //    this stack is not empty
    // Post-condition:
    //    returns the top element of this stack (but does not modify the
    //    stack)
    // Constraints:
    //    O(1) worst-case running time
    virtual int top() const = 0;
    
    virtual void print() =0;
}; // class Stack_base
class vector_Stack:public Stack_base
{
private:
    vector<int> v;
public:
    // removes the last element and sends it copy
    vector_Stack(): v(){}
    
    int pop()
    {
        if(is_empty())
        {
            cout<<"the stack is empty so we cant remove";
            return -1;
        }
        int result=v.back();
        v.pop_back();
        return result;
    }
    int top()const
    {
        if(is_empty())
        {
            cout<<"the stack is emoty so we cant remove";
            return -1;
        }
        return v.back();
    }
    void push(int x)
    {
        v.push_back(x);
    }
    bool is_empty() const
    {
        return v.empty();
    }
    void print()
    {
        if(v.size()==0)
            cout<<"the stack is empty"<<endl;
        while(!is_empty())
        {
            cout<<pop();
            cout<<endl;
        }
        
    }
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector_Stack s1;
    vector_Stack s2;
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    if(s2.is_empty())
    {
        for(int i=0;i<4;i++)
        {
            s2.push(s1.pop());
        }
        cout<<"now we will print"<<endl;
        s2.print();
    }
    
    //how it works is like
    // given all the outputs and u would like to implement in a queue way .what we will do is that,we will make 2 different stacks ,the stack one will be for push and the stack 2 will be for dequeue.We will input all the values in the stack 1 using the push operation.after that we will check if the stack 2 is empty.if it is empty then will copy all the elements of the stack 1 and paste it to the stack 2.Or what we will do is that,we will pop() the element in the stack 1 and push it into the stack 2. Once we are done with all the pop and push and we have our stack 2 ready.We can finally use the print command on the stack 2 ,which will start poping from the last element of the vector.As the stacks follow the rule of LIFO .And the end resultant order of the elements will be a queue.
    
    std::cout << "Hello, World!\n";
    return 0;
}
