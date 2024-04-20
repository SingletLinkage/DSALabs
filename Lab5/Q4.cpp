#include <iostream>

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

class List{
    public:
    Node* head;

    List(){
        this->head = NULL;
    }

    void insert(int value){
        Node* newNode = new Node(value);
        newNode->next = this->head;
        this->head = newNode;
    }

    void print(){
        Node* temp = this->head;

        while(temp!=NULL){
            cout << temp->value << " ";
            temp = temp->next;
        }
    }
};


class MinHeap{
    public:
    Node* arr[INT16_MAX];
    int last_idx;

    MinHeap(){
        this->arr[0] = NULL;
        this->last_idx = 1;
    }

    bool empty(){
        return (this->last_idx == 1);
    }

    void push(Node* node){
        this->arr[this->last_idx] = node;
        this->min_heapify(this->last_idx);
        this->last_idx++;
    }

    void min_heapify(int idx){
        int child = idx;
        int parent = idx/2;
        Node* temp;

        while(parent != 0){
            if (this->arr[parent]->value <= this->arr[child]->value){
                break;
            }else{
                temp = this->arr[child];
                this->arr[child] = this->arr[parent];
                this->arr[parent] = temp;
            }
            child = parent;
            parent = parent / 2;
        }
    }

    Node* top(){
        return this->arr[1];
    }

    void print(){
        for (int i=1; i<this->last_idx; i++){
            cout << this->arr[i]->value << " ";
        }
        cout << endl;
    }

    void pop(){
        this->arr[1] = this->arr[this->last_idx-1];
        // take this to correct position now
        int idx = 1, left, right;
        Node* temp;

        while (1){
            left=2*idx;
            right=left+1;

            if (left >= this->last_idx){
                break;
            }else if(right >= this->last_idx || this->arr[left]->value < this->arr[right]->value){
                temp = this->arr[idx];
                this->arr[idx] = this->arr[left];
                this->arr[left] = temp;
                idx = left;
            }else{
                temp = this->arr[idx];
                this->arr[idx] = this->arr[right];
                this->arr[right] = temp;
                idx = right;
            }
        }
        this->last_idx--;
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

    MinHeap* minHeap = new MinHeap();
    List* answer = new List();
    Node* temp;

    minHeap->push(h1);
    minHeap->push(h2);
    minHeap->push(h3);
    minHeap->push(h4);

    while (!minHeap->empty()){
        temp = minHeap->top();
        minHeap->pop();
        answer->insert(temp->value);

        if (temp->next != NULL){
            minHeap->push(temp->next);
        }
    }

    answer->print();

    cout << endl;

    return 0;
}

int main1(){
    MinHeap* mheap = new MinHeap();
    mheap->push(new Node(50));
    cout << "pushed 50" << endl;
    mheap->push(new Node(60));
    cout << "pushed 60" << endl;
    mheap->push(new Node(40));
    mheap->push(new Node(20));
    mheap->push(new Node(90));
    mheap->push(new Node(10));
    mheap->push(new Node(100));
    mheap->print();
    mheap->pop();
    mheap->print();

    return 0;
}