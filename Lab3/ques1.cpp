//Implement Tower of Hanoi on Stack using Linked list
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
    }
};

class Stack{
    public:
    Node* top;
    string name;

    Stack(string name){
        this -> top = NULL;
        this->name = name;
    }

    int peek(){
        if (top != NULL)
            return top->data;
        else
            cout << "Empty Stack";
            exit(1);
    }

    void pop(){
        if (top != NULL)
            top = top->next;
        else
            cout << "Empty Stack" << endl;
    }

    void push(int data){
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    void display(){
        Node* temp = top;
        while (temp != NULL){
            cout << temp->data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
};

void moveDisk(Stack* from, Stack* to){
    int disk = from->peek();
    from -> pop();
    to -> push(disk);
    cout << "Moved disk " << disk << "from " << from->name << " to " << to->name << endl;
}

void towerOfHanoi(int num, Stack* from, Stack* to, Stack* aux){
    if (num==1){
        moveDisk(from, to);
        return;
    }
    towerOfHanoi(num-1, from, aux, to);
    moveDisk(from, to);
    towerOfHanoi(num-1, aux, to, from);
}


int main(){
    Stack* A = new Stack("A");
    Stack* B = new Stack("B");
    Stack* C = new Stack("C");

    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    for(int i=n; i>0; i--){
        A->push(i);
    }
    cout << "Initial Stack A: ";
    A -> display();

    towerOfHanoi(n, A, C, B);

    cout << "Final stack C: ";
    C -> display();
    return 0;
}