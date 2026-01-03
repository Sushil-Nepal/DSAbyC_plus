#include<iostream>
#include "Stack.h"
using namespace std;
int main(){
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.display();
    cout<<stack.pop()<<endl;
    stack.display();
    cout<<stack.pop()<<endl;
    stack.display();
    cout<<stack.peak()<<endl;
    stack.display();
    cout<<stack.getSize()<<endl;
    return 0;
}