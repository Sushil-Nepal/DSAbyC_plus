#ifndef LINKEDLIST_H
#define LINKEDLIST_H
template <typename T>
class Linkedlist;
template <typename T>
class Node{
    private:
        T data;
        Node<T> *next;
    public:
        Node(T value);
        template <typename U>
        friend class Linkedlist;
};
template <typename T>
Node<T>::Node(T value){
    data=value;
    next=nullptr;
}
template <typename T>
class Linkedlist{
    private:
        Node<T> *head;
        int size;
    public:
        Linkedlist();

        int isEmpty();

        int insertAtEnd(T value);
        int insertAtStart(T value);
        int insertAtPosition(T value,int  pos);

        int deleteStart();
        int deleteEnd();
        int deleteValue(T value);

        Node<T>* traverse(int pos);
        Node<T>* search(T value);
        void display();
        int clear();
        ~Linkedlist();
};
#endif