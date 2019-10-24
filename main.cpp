#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Node.h"

using namespace std;

int main() {
    int x;
    Node* head= new Node();
    Node* current = head;
    cout<<"enter a list of integers and -1 to stop"<<endl;
    cin>>x;
    //populate the linked list with at least 7 nodes
    while(x!=-1){
       Node* n= new Node(x);
       current->InsertAfter(n);
       current=n; //current=current->getNext;
       cin>>x;
    }

    //print the nodes of the linked list
    current=head->getNext();
    while(current!=nullptr)
    {
        current->printNode();
        current=current->getNext();
    }

    cout << endl;

    //1) find the node that has the minimum value
    int min;
    Node * next;
    current=head->getNext();
    min = current->getValue();
    while (current!=nullptr && current->getNext()!= nullptr){
        next = current->getNext();
        if (min > next->getValue()){
            min = next->getValue();
        }
        current = current->getNext();
    }
    cout << "Minimum value is: " << min << endl;
    cout << endl;

    //2) remove the 4th node from the list

    current = head->getNext();
    Node * previous = head->getNext();
    current = current->getNext();
    current = current->getNext();
    previous = previous->getNext();
    current = current->getNext();
    previous = previous->getNext();
    previous->setNext(current->getNext());
    current->setNext(nullptr);
    delete(current);

    //Prints list

    cout << "List with 4th element removed:" << endl;
    current=head->getNext();
    while(current!=nullptr)
    {
        current->printNode();
        current=current->getNext();
    }
    cout << endl;


    //3) remove the last node

    current = head->getNext();
    previous = head->getNext();
    current = current->getNext();

    while(current != nullptr && current->getNext()!= nullptr){
        current = current->getNext();
        previous = previous->getNext();
    }

    previous->setNext(nullptr);
    delete(current);

    //Prints list
    cout << "List with last element removed:" << endl;

    current=head->getNext();
    while(current!=nullptr)
    {
        current->printNode();
        current=current->getNext();
    }
    cout << endl;

    //4) remove the first node
    current = head->getNext();
    head->setNext(current->getNext());
    current->setNext(nullptr);
    delete(current);

    //Prints list
    cout << "List with first element removed:" << endl;

    current=head->getNext();
    while(current!=nullptr)
    {
        current->printNode();
        current=current->getNext();
    }
    cout << endl;


    //6) delete all nodes
    current = head->getNext();
    while(head != nullptr && head->getNext()!= nullptr) {
        current = head->getNext();
        head->setNext(current->getNext());
        current->setNext(nullptr);
        delete (current);
    }

    //Prints list
    cout << "List with all elements removed:" << endl;

    current=head->getNext();
    while(current!=nullptr)
    {
        current->printNode();
        current=current->getNext();
    }
    cout << endl;

    cout << "Finished deleting all nodes" << endl;

    return 0;
}