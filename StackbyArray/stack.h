#ifndef STACK_H
#define STACK_H
template <typename T>
class Stack{
    private:
        int top;
        int maxSize;
        T *items;
    public:
        Stack(int size){
            top=-1;
            maxSize=size;
            items= new T[size];
        }
        ~Stack(){
            delete[] items;
        }
        int isFull();
        int isEmpty();
        int push(T value);
        T pop();
        T peak();
        void display(); 
};
#endif