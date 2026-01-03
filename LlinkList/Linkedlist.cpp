#include<iostream>
#include "Linkedlist.h"
#include<string>
using namespace std;
template <typename T>
//return Size
Linkedlist<T>::Linkedlist(){
   size=0;
}


template <typename T>
int Linkedlist<T>::isEmpty(){
   return (head==nullptr);
} 



template <typename T>
//traverse to LinkedList tos specific possition
Node<T>* Linkedlist<T>::traverse(int pos){
     if(pos<0||pos>=size||isEmpty()){
        return nullptr;
     }
     Node<T>* temp=head;
     for(int i=0;i<pos;i++){
        temp=temp->next;
     }
     return temp;
}



template<typename T>
Node<T>* Linkedlist<T>::search(T value){
      Node<T>* temp=head;
      if(isEmpty()){
         return nullptr;
      }
      while(temp!=nullptr){
         if(temp->data==value){
            return temp;
         }
         temp=temp->next;
      }
      return nullptr;
}



template <typename T>
int Linkedlist<T>::insertAtStart(T value){
     Node<T>* newNode=new Node<T>(value);
     newNode->next=head;
     head=newNode;
     size++;
     return 1;
}


template <typename T>
int Linkedlist<T>::insertAtEnd(T value){
     if(isEmpty()){
        insertAtStart(value);
        return 1;
     }
     Node<T>* newNode=new Node<T>(value);
     Node<T>* temp=traverse(size-1);
     temp->next=newNode;
     size++;
     return 1;
}


template <typename T>
int Linkedlist<T>::insertAtPosition(T value,int pos){
     if(pos==0||isEmpty()){
        insertAtStart(value);
        return 1;
     }
     Node<T>* newNode=new Node<T>(value);
     Node<T>* preNode=traverse(pos-1);//1 possition before insert
     if (preNode == nullptr) {
        return 0;
     }
     newNode->next=preNode->next;
     preNode->next=newNode;
     size++;
     return 1;
}


//delete 
template <typename T>
int Linkedlist<T>::deleteStart(){
   if(isEmpty()){
      return 0;
   }
   Node<T>* temp=head;
   head=head->next;
   delete temp;
   size--;
   return 1;
}


template <typename T>
int Linkedlist<T>::deleteEnd(){
   if(isEmpty()){
      return 0;
   }
   if(size==1){
      deleteStart();
      return 1;
   }
   Node<T>* preNode=traverse(size-2);
   Node<T>* lastNode=preNode->next;
   preNode->next=nullptr;
   delete  lastNode;
   size--;
   return 1;
}



template <typename T>
int Linkedlist<T>::deleteValue(T value){
   if(isEmpty()){
      return 0;
   }
   if(head->data==value){
      Node<T>* temp=head;
      head=head->next;
      delete  temp;
      size--;
      return 1;
   }
   Node<T>* preNode=head;
   Node<T>* currNode=head->next;
   while(currNode!=nullptr){
         if(currNode->data==value){
            preNode->next=currNode->next;
            delete  currNode;
            size--;
            return 1;
            break;
         }
         currNode=currNode->next;
         preNode=preNode->next;
   }
   return 0;
}



template <typename T>
int Linkedlist<T>::clear(){
   while (head!=nullptr)
   {
      deleteStart();
   }
   return 0;
}




template <typename T>
Linkedlist<T>::~Linkedlist(){
   clear();
}
template <typename T>
void Linkedlist<T>::display(){
    Node<T>* temp=head;
    while (temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NUll"<<endl;
}


template class Linkedlist<int>;
template class Linkedlist<char>;
template class Linkedlist<float>;
template class Linkedlist<short>;
template class Linkedlist<double>;
template class Linkedlist<long>;
template class Linkedlist<string>;
template class Node<char>;
template class Node<int>;
template class Node<float>;
template class Node<short>;
template class Node<double>;
template class Node<long>;
template class Node<string>;