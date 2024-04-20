#include <iostream>
#include <queue>

using namespace std;
class Node{
    public:
    int value;
    Node* next;

    Node(int value){
        this->value=value;
        this->next=NULL;
    }
};

class compare{
    public:
    bool operator()(Node* a, Node* b){
        return a->value > b->value;
    }
};

int main(){
    Node* h1 = new Node(2);
    h1->next = new Node(4);
    h1->next->next = new Node(6);

    Node* h2 = new Node(1);
    h2->next = new Node(5);

    Node* h3 = new Node(1);
    h3->next = new Node(1);
    h3->next->next = new Node(3);
    h3->next->next->next = new Node(7);

    Node* h4 = new Node(8);

    priority_queue<Node*, vector<Node*>, compare> minHeap; 
    vector<Node*> answer;
    Node* temp;

    minHeap.push(h1);
    minHeap.push(h2);
    minHeap.push(h3);
    minHeap.push(h4);

    while (!minHeap.empty()){
        temp = minHeap.top();
        minHeap.pop();
        answer.push_back(temp);

        if (temp->next != NULL){
            minHeap.push(temp->next);
        }
    }

    for (Node* i : answer){
        cout << i->value << " ";
    }
    cout << endl;

    return 0;
}