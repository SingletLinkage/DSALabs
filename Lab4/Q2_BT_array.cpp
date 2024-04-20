// Implement Binary Tree Using Array:

// Assuming:
//           3
//        2     5
//       7 8   9 0
// is stored as: [3, 2, 5, 7, 8, 9, 0] <-- Level wise
#include <iostream>
#include <math.h>
using namespace std;

class Tree{
    public:
    int* array;
    int height;

    Tree(int height){
        this->height = height;
        this->array = new int(pow(2, height)-1);
        for (int _=0; _<pow(2, height)-1; _++){
            this->array[_] = INT64_MAX;
        }
    }
    
    void display(){
        int idx = 0;
        for (int i=0; i<height; i++){
            for (int j=0; i<pow(2, i); j++){
                cout << array[idx] << " ";
                idx += 1;
            }
            cout << endl;
        }
    }

    int search(int value){
        for (int i=0; i<pow(2, this->height)-1; i++){
            if (this->array[i] == value){
                return i;
            }
        }
        return -1;
    }

    void insert_root(int value){
        if (this->array[0] == INT64_MAX){
            array[0] = value;
        }else{
            cout << "Tree Already has a root" << endl;
        }
    }

    void forced_insert(int value){
        for (int i=0; i<pow(2, this->height)-1; i++){
            if (this->array[i] == INT64_MAX){
                this->array[i] = value;
            }
        }
    }

    void insert(int parent, int value){
        // finding index of parent:
        int parent_idx = -1;
        for (int i=0; i<pow(2, this->height)-1; i++){
            if (this->array[i] == parent){
                parent_idx = i;
                break;
            }
        }
        if (parent_idx==-1){
            cout << "Parent Value not present" << endl;
            return;
        }

        int left_child_index = 2*parent_idx + 1;
        int right_child_index = 2*parent_idx + 1;

        if (this->array[left_child_index] != INT64_MAX){
            this->array[left_child_index] = value;
        }else if (this->array[right_child_index] != INT64_MAX){
            this->array[right_child_index] = value;
        }else{
            cout << "No Space Empty, can't insert element" << endl;
        }
    }

    void delete_node(int value){
        for (int i=0; i<pow(2, this->height)-1; i++){
            if (this->array[i] == value){
                this->array[i] = INT64_MAX;
                return;
            }
        }
        cout << "Value does not exist" << endl;
    }
};