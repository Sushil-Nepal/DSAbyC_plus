#include<iostream>
#include <stdlib.h>
#include<cmath>
#include<string>
#include "../StackByLinkedlist/Stack.h"
using namespace std;
class Expression{
    private:
        string infix;
        string postfix;
        Stack<char> stack;
    public:
        Expression(){
           
        }
        void getInfix();
        void toPostfix();
        int isOperator(char ope);//check if given char is operator yes return precidence not return 0;
        int isValid(char c); //check expression is valid  or not
        void display(); 
        float calculation();
        float calculate(int num1,int num2,char ope);
};
void Expression::display(){
    cout<<postfix;
}
void Expression::getInfix(){
    cin>>infix;
}
int Expression::isOperator(char ope){
    switch (ope)
    {
    case '+':
    case '-':
        return 2;
        break;;
    case '*':
    case '/':
        return 3;
         break;
    case '^':
        return 4;
         break;
    case '(':
    case  ')':
        return 1;
        break;
    default:
        return 0;
    }
}
int Expression::isValid(char c){
    switch (c)
    {
    case '0':
    case '1':   
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return 9;
    default:
        break;
    }
    return isOperator(c);
}
void Expression::toPostfix(){
    string num="";
    infix+="\0";
    int i=0;
    while(infix[i]!='\0'){
        char c=infix[i];
        if(!isValid(c)){
            cout<<"Syntax Error";
            return;
        }else if(!isOperator(c)){
            num+=c;
        }
        else if(isOperator(c)){
            postfix+=num+" ";
            num="";
            if(c=='('||stack.isEmpty()){
                stack.push(c);
            }else if(c==')'){
                char temp;
                while(!stack.isEmpty()){
                    if(stack.peak()=='('){
                        stack.pop();
                        break;
                    }
                    postfix+=stack.pop();
                }   
            }else if((isOperator(c)>isOperator(stack.peak()))||
            (isOperator(c)==isOperator(stack.peak())&&isOperator(c)==4)){
                stack.push(c);
            }else if((isOperator(c)<isOperator(stack.peak()))||
            (isOperator(c)==isOperator(stack.peak())&&isOperator(c)!=4)){
                postfix+=stack.pop();
                continue;
            }
        }
        i++;
    }
    postfix+=num+" ";
    //for remain operator in stack
    while(!stack.isEmpty()){
        postfix+=stack.pop();
    }
}
float Expression::calculate(int num1,int num2,char ope){
    switch(ope){
        case '+':
            return num1+num2;
        case '-':
            return num1-num2;
        case '*':
            return num1*num2;
        case '/':
            return num1/num2;
        case '^':
             return pow(num1,num2);
        default:
             cout<<"Error on Calculate";
    }
}
float Expression::calculation(){
    float solution=0.0;
    postfix+="\0";
    Stack<float> s;
    int i=0;
    float num1;
    float num2;
    float ans;
    string num;
    while(postfix[i]!='\0'){
        char c=postfix[i];
        if(!isOperator(c)&&c!=' '&&isValid(c)){
            num+=c;
        }else if(!isOperator(c)&&c==' '&&num!=""){
            s.push(float(stoi(num)));//string to number to float
            num="";
        }else if(isOperator(c)){
            num1=s.pop();
            num2=s.pop();
            ans=calculate(num2,num1,c);
            s.push(ans);
        }
        i++;
    }
    return float(s.pop());
}
int main(){
    Expression e1;
    e1.getInfix();
    e1.toPostfix();
    e1.display();
    cout<<endl<<"ans:"<<e1.calculation();
    return 0;
} 