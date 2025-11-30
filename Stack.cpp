#include<iostream>
#define MAX 5
using namespace std;
template <typename T>
class Stack{
   T stack[MAX];
   T top;
   public:
    Stack(){
        top=-1;
        stack[MAX];
    }
    int isFull();
    int isEmpty();
    int push();
    int pop();
    int peak();
    void display();
};
int main(){
    int choice;
    Stack<char> s;
    while(1){
        cout<<"\n=====Stack Menu=====";
        cout<<"\n 1.Push\n 2.pop\n 3.peak \n 4.display \n 5.exit\n";
        cout<<"====================\n";
        cout<<"Choose the Option";
        cin>>choice;
        if(choice==5){
            break;
        }
        switch(choice){
            case 1:
                s.push();
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peak();
                break;
            case 4:
                cout<<"Stack is:";
                 s.display();
                break;
            default:
                cout<<".....Invalid Input.....";    
        }
    }
    return 0;
}
template <typename T>
int Stack<T>::isFull(){
    return (top==MAX-1);
}
template <typename T>
int Stack<T>:: isEmpty(){
    return (top==-1);
}
template <typename T>
int Stack<T>::push(){
    if(isFull()){
        cout<<"\nStack is Full\nCan Not pushed\n";
        return 0;
    }cout<<"Enter value to be pushed:";
    cin>>stack[++top];
    return 1;
}
template <typename T>
int Stack<T>::pop(){
    if(!isEmpty()){
        cout<<"pop value is:"<<stack[top--];
    }else{
        cout<<"Stack Is Empty";
    }
}
template <typename T>
int Stack<T>::peak(){
    if(!isEmpty()){
        cout<<"Peak value is:"<<stack[top];
    }else{
        cout<<"Stack Is Empty";
    }
}
template <typename T>
void Stack<T>::display(){
    cout<<"[";
        for(int i=0;i<=top;i++){
            cout<<stack[i]<<",";
        }
    cout<<"]\n";
}
