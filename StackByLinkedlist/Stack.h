#ifndef STACK_H
#define STACK_H
template <typename T>
class Stack;
template <typename T>
class Node{
    private:
        T data;
        Node<T> *next;
    public:
        Node(T value);
        template <typename U>
        friend class Stack;
};
template <typename T>
Node<T>::Node(T vlaue){
    data=vlaue;
    next=nullptr;
}
template <typename T>
class Stack{
    private:
        int size;
        Node<T>* top;
    public:
        Stack(){
            size=0;
            top=nullptr;
        }
        int isEmpty();
        int push(T value);
        T pop();
        T peak();
        int getSize();
        void display();
};
#endif