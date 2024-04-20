# include <iostream>
using namespace std;

// Implement SkipLanes

class Node{
    public:
    Node* next;
    int value;
    Node* down;

    Node(int val){
        this->next = NULL;
        this->down = NULL;
        this->value = value;
    }
};

class Lane{
    public:
    Node* head;

    Lane(){
        head=NULL;
    }

    void append(int val){
        Node* temp = new Node(val);
        temp->value = val;
        temp->next = head;
        head = temp;
    }

    void link(Node* node){
        Node* temp = new Node(node->value);
        temp->value = node->value;
        temp->next = head;
        temp->down = node;
        head = temp;
    }

    void display(){
        Node* temp = head;
        while (temp != NULL){
            cout << temp->value << "  " << temp << " linked to: " << temp->down << "\n";
            temp = temp->next;
        }
        cout << "\n\n";
    }
};

int main(){
    // implement first layer (Normal Lane)
    Lane* NormalLane = new Lane();

    for(int i=0; i<200; i++){
        NormalLane->append(i);
    }
    cout << "Normal Lane: " << endl;
    NormalLane->display();

    // Level 1 Express Lane
    // Skips every 5 elements

    Lane* ExpressLane_temp = new Lane();
    Lane* ExpressLane = new Lane();
    Node* prev_head = NormalLane->head;
    int counter = 0;

    while(prev_head!=NULL){
        if (counter % 5 == 0){
            ExpressLane_temp->link(prev_head);
        }
        counter ++;
        prev_head = prev_head->next;
    }

    prev_head = ExpressLane_temp -> head;
    while (prev_head!=NULL){
        ExpressLane->link(prev_head->down);
        prev_head = prev_head->next;
    }

    cout << "Express Lane" << endl;
    ExpressLane->display();


    // Searching for a key in Normal Lane
    cout << "Searching on Normal Lane" << endl;
    int key = 127;
    int comparisons = 0;
    Node* normal_head = NormalLane -> head;

    while(normal_head!=NULL){
        comparisons ++ ;
        if (normal_head->value == key){
            cout << "Present!\n";
            break;
        }else if (normal_head->value < key){
            cout << "Not Present!\n";
            break;
        }
        normal_head = normal_head -> next;
    }

    cout << "Comparison count: " << comparisons << endl;


    // Searching for a key in Skip List mode
    cout << "Searching on ExpressLane" << endl;
    comparisons = 0;
    Node* start = ExpressLane -> head;

    while(start!=NULL){
        comparisons++;
        if (start->value == key){
            cout << "Present!\n";
            break;
        }
        if (start->next == NULL  || start->next->value < key){
            start = start -> down;
        }else{
            start = start->next;
        }
    }
    cout << comparisons << endl;
    return 0;
}