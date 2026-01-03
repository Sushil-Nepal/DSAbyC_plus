#include<iostream>
#include "Stack.h"
using namespace std;
template <typename T>
int Stack<T>::isEmpty(){
   return top==nullptr;
}
template <typename T>
int Stack<T>::push(T value){
    Node<T>* newNode=new Node<T>(value);
    if(isEmpty()){
        top=newNode;
        size++;
        return 1;
    }
    newNode->next=top;
    top=newNode;
    size++;
    return 1;
}
template <typename T>
T Stack<T>::pop(){
    T t;
    if(isEmpty()){
        return T();
    }
    Node<T> *temp=top;
    top=top->next;
    t=temp->data;
    delete temp;
    size--;
    return t;
}
template <typename T>
T Stack<T>::peak(){
    if(isEmpty()){
        return T();
    }
    return top->data;
}
template <typename T>
void Stack<T>::display(){
    Node<T> *temp=top;
    cout<<"[";
    while(temp!=nullptr){
        cout<<temp->data<<",";
        temp=temp->next;
    }
    cout<<"]"<<endl;
}
template <typename T>
int Stack<T>::getSize(){
    return size;
}


template class Stack<int>;
template class Stack<char>;
template class Stack<float>;
template class Stack<short>;
template class Stack<double>;
template class Stack<long>;
template class Stack<string>;
template class Node<char>;
template class Node<int>;
template class Node<float>;
template class Node<short>;
template class Node<double>;
template class Node<long>;
template class Node<string>;