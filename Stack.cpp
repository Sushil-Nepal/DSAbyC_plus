#include<iostream>
#define MAX 5
using namespace std;
class Stack{
   int stack[MAX];
   int top;
   public:
    Stack(){
        top=-1;
        stack[MAX];
    }
    int isFull(){
        return (top==MAX-1);
    }
    int isEmpty(){
        return (top==-1);
    }
    int push(int value){
        if(isFull()){
            printf("\nStack is Full\n");
            return 0;
        }
        stack[++top]=value;
        return 1;
    }
    int pop(){
        if(isEmpty()){
            printf("\nStack is Empty:\n");
        }
        return stack[top--];
    }
    int peak(){
        if(isEmpty()){
            printf("\n Stack is Empty:\n");
        }
        return stack[top];
    }

    void display(){
        printf("[");
        for(int i=0;i<=top;i++){
            printf("%d,",stack[i]);
        }
        printf("]\n");
    }
};
int main(){
    int value,choice;
    Stack s;
    while(1){
        printf("\n=====Stack Menu=====");
        printf("\n 1.Push\n 2.pop\n 3.peak \n 4.display \n 5.exit\n");
        printf("====================\n");
        printf("Choose the Option");
        if(choice==5){
            break;
        }
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter the value to be Pushed:");
                scanf("%d",&value);
                if(!s.push(value)){
                    printf("\nFailed to Push\n");
                    break;
                }
                printf("\nPush Sucessfully\n");
                break;
            case 2:
                value=s.pop();
                printf("\nPop Value is:%d\n",value);
                break;
            case 3:
                value=s.peak();
                printf("Peak Value is:%d \n",value);
                break;
            case 4:
                printf("Stack is:");
                 s.display();
                break;
            default:
                printf(".....Invalid Input.....");    
        }
    }
    return 0;
}