#include<iostream>
#include "stack.h"
using namespace std;
int main(){
    int choice;
    Stack<char> s(5);
    char value;
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
                cout<<"Enter Char to Push:"<<endl;
                cin>>value;
                s.push(value);
                break;
            case 2:
                value=s.pop();
                cout<<"pop value is :"<<value<<endl;
                break;
            case 3:
                value=s.peak();
                cout<<"peak value is :"<<value<<endl;
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