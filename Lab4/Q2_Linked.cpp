#include <iostream>
using namespace std; 
class Node{
    public:
    Node* leftChild;
    Node* rightChild;
    int value;

    Node(int value){
        this->leftChild = NULL;
        this->rightChild = NULL;
        this->value = value;
    }
};

class BinaryTree{
    public:
    Node* root;

    BinaryTree(){
        this->root=NULL;
    }

    void insert(int value){
        if (this->root == NULL){
            this->root = new Node(value);
            return;
        }

        Node* temp = this->root;
        while (temp->leftChild!=NULL){
            temp = temp->leftChild;
        }

        temp->leftChild = new Node(value);
    }

    Node* search_recursive(Node* node, int value){
        if ((node!=NULL) and (node->value != value))
        {
            cout << "Arrived at: " << node->value << endl;
            this->search_recursive(node->leftChild, value);
            this->search_recursive(node->rightChild, value);
        }

        if (node!=NULL && node->value == value){
            cout << "Found Value!" << endl;
            return node;
        }
        return node;
    }

    bool search(int value){
        Node* temp = this->search_recursive(this->root, value);
        if (temp!=NULL){
            cout << temp->value << endl;
            return temp->value == value;
        }else{
            return false;
        }
    }

    void remove(int value){
    }
};


int main(){
    BinaryTree* tree = new BinaryTree();
    tree->root = new Node(5);
    tree->root->leftChild = new Node(3);
    tree->root->rightChild = new Node(7);
    tree->root->leftChild->leftChild = new Node(1);
    tree->root->leftChild->rightChild = new Node(2);
    tree->root->rightChild->leftChild = new Node(9);
    tree->root->rightChild->rightChild = new Node(8);
    /*
                    5
                3       7
              1  2    9   8   
    */

    cout << tree->search(2) << endl;
}