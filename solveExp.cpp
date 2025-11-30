#include<iostream>
#include<cmath>
#include<string>
#define MAX_OPE 7 //total operators
using namespace std;
//Main Stack class ____Status--Work well
template <typename T>
class Stack{
    protected:
        int top;
        int maxSize;
        int flag;
        T *mainStack;
    public:
        Stack(){
            top=-1;
            flag=0;
            maxSize=10;
            mainStack=new T[maxSize];
        }
        Stack(int len){
            top=-1;
            flag=0;
            maxSize=len;
            mainStack=new T[maxSize];
        }
        ~Stack(){
            delete[] mainStack;
        }
        void setTop(int t){
            top=t;
        }
        int stackSize(){
            return top+1;
        }
        int canPOP(){
            return flag;
        }
        int isFull();
        int isEmpty();
        int push(T value);
        T pop();
        T peak();
        void displayStack();
};
template <typename T>
void Stack<T>::displayStack(){
    cout<<"[";
    for(int i=0;i<=top;i++){
        cout<<mainStack[i]<<",";
    }
    cout<<"]"<<endl;
}
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
        cout<<"\nOut of memory\n";
        return 0;
    };
    mainStack[++top]=value;
    flag=1;
    return 1;
}
template <typename T>
T Stack<T>::pop(){
    if(!isEmpty()){
        return mainStack[top--];
    }else{
        flag=0;
        return 0;
    }
}
template <typename T>
T Stack<T>::peak(){
    if(!isEmpty()){
        return mainStack[top];
    }else{
        flag=0;
        return 0;
    }
}
class Input{
    protected:
        string inputString;
        Stack <char> operators;
        Stack <char> decimal;
    public:
    Input(){
            cin>>inputString;
            char temp1[]={'-','+','/','*','(',')','^'};
            char temp2[]={'0','1','2','3','4','5','6','7','8','9'};
            for(int i=0;i<10;i++){
                if(i<MAX_OPE){
                    operators.push(temp1[i]);
                }
            decimal.push(temp2[i]);
            }
        }
        string getString(){
            return inputString;
        }
        void display();
        int checkPer(char ch);    
};
void Input:: display(){
            cout<<inputString<<endl;
            operators.displayStack();
            decimal.displayStack();
        }
int Input:: checkPer(char ch){
    switch (ch)
    {
    case '-':
    case '+':
        return 1;
    case '/':
    case '*':
        return 2;
    case '(':
    case ')':
        return 3; 
    case '^':
        return 4;
    default:
        return 0;
    }
}
class Expression{
    Input inp;
    int noOfOperator;
    int flag=1;
    string postfix;
    Stack <char> postfixStack;
    Stack <int> calculation;
    public:
        Expression():postfixStack(inp.getString().length()){
            noOfOperator=0;
            postfix="";
        }
        void display(){
            //np.display();
                cout<<postfix;
                postfixStack.displayStack();
            // calculation.displayStack();
            cout<<"="<<calculation.pop();
        }
        void infixToPostfix();
        void claculateResult();
        float operation(int oprand1,char ope,int operand2);
};
 float Expression:: operation(int operand1,char ope,int operand2){
    switch (ope)
    {
        case '-':
            return operand1-operand2;
        case '+':
            return operand1+operand2;
        case '/':
            return operand1/operand2;
        case '*':
            return  operand1*operand2;
        case '^':
            return pow(operand1,operand2);
        default:
            flag=0;
            return 0;
    }
 }
void Expression::claculateResult(){
    float num=0;
    float n,a,b,ans;
    for(int i=0;i<postfix.length();i++){
        if(inp.checkPer(postfix[i])){
             calculation.push(num);
             num=0;
            if(calculation.stackSize()>=2){
                a=calculation.pop();
                b=calculation.pop();
                ans=operation(b,postfix[i],a);
                calculation.push(ans);
            }
        }
        else if(postfix[i]!=' '){
            n=postfix[i]-'0';//chage to number
            num+=n;
        }else{
            calculation.push(num);
            num=0;
        }

    }
}
void Expression::infixToPostfix()
{
    string temp;
    string sumChar;
    temp=inp.getString();
    for(int i=0;i<temp.length();i++){
        if(!inp.checkPer(temp[i])){
            sumChar=sumChar+temp[i];
        }else if(postfixStack.isEmpty()){
            postfix=postfix+string(" ")+sumChar;
            sumChar="";
            postfixStack.push(temp[i]);
        }else if(inp.checkPer(temp[i])>inp.checkPer(postfixStack.peak())){
            postfix=postfix+string(" ")+sumChar;
            sumChar="";
            postfixStack.push(temp[i]);
        }else if(inp.checkPer(temp[i])<=inp.checkPer(postfixStack.peak())){
            postfix=postfix+string(" ")+sumChar;
            sumChar="";
            while(inp.checkPer(temp[i])<=inp.checkPer(postfixStack.peak())){
                postfix=postfix+postfixStack.pop();
            }
            cout<<postfixStack.push(temp[i]);
        }else{
            
        }
        if(i+1==temp.length()){
            postfix=postfix+string(" ")+sumChar;
            sumChar="";
            while(postfixStack.canPOP()){
                postfix=postfix+postfixStack.pop();
            }
        }        
    }
}
void checkStack(){
    int a=1;
    Stack<int> s;
    s.push(a);
    s.displayStack();
    cout<<s.peak();
    cout<<s.pop();
    s.displayStack();
}
void checkExpression(){
    Expression e;
    e.infixToPostfix();
    e.claculateResult();
    e.display();
}
int main(){
    //Check Stack Class work or not
    //checkStack();
    //check Expression Class
    //checkExpression();
    Expression e;
    e.infixToPostfix();
    e.claculateResult();
    e.display();
    return 0;
}
