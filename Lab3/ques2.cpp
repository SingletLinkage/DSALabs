// Implement Parenthesis Matching on Stack using Linked list

#include <iostream>
using namespace std;

class Node{
    public:
    char data;
    Node* next;

    Node(char data){
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

    char peek(){
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

    void push(char data){
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

int main(){
    string str;
    Stack* stack = new Stack("expression");
    cout << "Enter the expression: ";
    getline(cin, str);
    bool flag = true;
    
    for (char ch : str){
        if (ch=='(' || ch=='{' || ch=='['){
            stack->push(ch);
        }else{
            if ((ch==']' and stack->peek()!='[') || (ch==')' and stack->peek()!='(') || (ch=='}' and stack->peek()!='{')){
                flag = false;
                break;
            }
        }
    }

    if (flag and (stack->peek() == NULL)){
        cout << "Parenthesis Matched" << endl;
    }else{
        cout << "Parenthesis Unmatched" << endl;
    }
    
}