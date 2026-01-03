#include<iostream>
#include "Linkedlist.h"
using namespace std;
int main(){
    // Linkedlist<int> linkInt;
    Linkedlist<char> linkInt;
    // linkInt.insertAtStart(10);
    // linkInt.insertAtEnd(20);
    // linkInt.insertAtPosition(15,1);
    // linkInt.insertAtEnd(25);
    // linkInt.insertAtStart(10);
    // linkInt.display();
    // linkInt.deleteStart();
    // linkInt.display();
    // linkInt.deleteEnd();
    // linkInt.display();
    // linkInt.deleteValue(15);
    // linkInt.display();
    // linkInt.clear();
    // linkInt.display();
    linkInt.insertAtStart('c');
    linkInt.insertAtEnd('t');
    linkInt.insertAtPosition('a',1);
    linkInt.insertAtEnd(' ');
    linkInt.insertAtStart(' ');
    linkInt.display();
    linkInt.deleteStart();
    linkInt.display();
    linkInt.deleteEnd();
    linkInt.display();
    linkInt.deleteValue('a');
    linkInt.display(); 
    linkInt.clear();
    linkInt.display();
    return 0; 
}