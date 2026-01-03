#include<iostream>
#include "stack.h"
#include<string.h>
using namespace std;
template <typename T>
int Stack<T>::isFull(){
    return (top==maxSize-1);
}
template <typename T>
int Stack<T>:: isEmpty(){
    return (top==-1);
}
template <typename T>
int Stack<T>::push(T value){
    if(isFull()){
        cout<<"\nStack is Full\nCan Not pushed\n";
        return 0;
    }
    items[++top]=value;
    return 1;
}
template <typename T>
T Stack<T>::pop(){
    T temp=(!isEmpty())?items[top--]:T();
    return temp;
}
template <typename T>
T Stack<T>::peak(){
    T temp=(!isEmpty())?items[top]:T();
    return temp;
}
template <typename T>
void Stack<T>::display(){
    cout<<"[";
        for(int i=0;i<=top;i++){
            cout<<items[i]<<",";
        }
    cout<<"]\n";
}
template class Stack<int>;
template class Stack<char>;
template class Stack<float>;
template class Stack<short>;
template class Stack<double>;
template class Stack<long>;
template class Stack<string>;
