// Implement the insertion sort algorithm using doubly linked list
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DLL{
    public:
    Node* head;
    DLL(){
        this->head=NULL;
    }

    void push(int data){
        Node* newNode = new Node(data);
        newNode->next = head;

        if (head != NULL){
            head->prev = newNode;
        }

        head = newNode;
    }

    void pop(Node* node){
        if (node->prev != NULL)
            (node->prev) -> next = node -> next;

        if(node->next != NULL)
            (node->next) -> prev = node -> prev;
    }

    void pushAfter(int data, Node* node){
        Node* newNode = new Node(data);
        newNode -> prev = node;
        newNode -> next = node->next;

        if (node->next != NULL){
            (node -> next) -> prev = newNode;
        }

        node -> next = newNode;
    }
    void display(){
        Node* node = this->head;
        while (node != NULL){
            // cout << "( data:" << node->data;
            // if (node->prev != NULL)
            // cout << ", prev:" << node->prev->data;
            // if (node->next != NULL)
            // cout << ", next:" << node->next->data << ") ";
            // node = node -> next;
            cout << (node -> data) << " ";
            node = node -> next;

        }
        cout << endl;
    }
};

int main(){
    DLL* list = new DLL();
    cout << "Enter number of elements: ";
    int num;
    cin >> num;
    cout << "Enter elements: ";

    int var;
    while(num > 0){
        cin >> var;
        list->push(var);
        num--;
    }

    cout << "Original: ";
    list->display();

    // Insertion sort:
    // 4 7 2 5 1
    Node* top = (list -> head) -> next;

    while (top != NULL){
        int key = top -> data;
        list -> pop(top);

        Node* aux = top -> prev;
        while((aux != NULL) && (key < aux->data)){
            aux = aux -> prev;
        }

        if (aux != NULL)
            list -> pushAfter(key, aux);
        else
            list -> push(key);
        
        top = top -> next;
    }
    cout << "After sorting: ";
    list -> display();
}