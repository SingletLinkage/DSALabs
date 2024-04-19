// Max Heap
#include <iostream>
using namespace std;

class MaxHeap{
    public:
    int heap[INT32_MAX];
    int lastidx;

    MaxHeap(){
        this->heap[0] = NULL;
        this->lastidx = 1;
    }

    void insert(int key){
        this->heap[this->lastidx] = key;
        this->max_heapify(this->lastidx);
        this->lastidx++;
    }

    void max_heapify(int idx){
        int child_idx = idx;
        int parent_idx = idx/2;
        int temp;
        while (parent_idx != NULL){
            if (this->heap[parent_idx] >= this->heap[child_idx]){
                break;
            }else{
                temp = this->heap[parent_idx];
                this->heap[parent_idx] = this->heap[child_idx];
                this->heap[child_idx] = temp;
            }
            child_idx = parent_idx;
            parent_idx /= 2;
        }
    }

    void remove(int val){
        int idx = NULL;
        for(int i=0; i<this->lastidx; i++){
            if (this->heap[i] == val){
                idx = i;
            }
        }

        if (idx != NULL){
            this->remove_idx(idx);
            this->lastidx--;
        }else{
            cout << "Element Not Found!" << endl;
        }
    }

    void remove_idx(int idx){
        int c1 = 2 * idx;
        int c2 = 2 * idx + 1;

        if (c1 >= this->lastidx){
            return;
        }

        if ((c2 >= this->lastidx) || (this->heap[c1] >= this->heap[c2])){
            this->heap[idx] = this->heap[c1];
            this->remove_idx(c1);
        }else{
            this->heap[idx] = this->heap[c2];
            this->remove_idx(c2);
        }

    }

    void print(){
        for (int i=1; i<this->lastidx; i++){
            cout << this->heap[i] << " ";
        }
        cout << endl;
    }

};

void heapify(int arr[], int size, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if (left < size && arr[left] > arr[largest]){
        largest = left;
    }
    if (right < size && arr[right] > arr[largest]){
        largest = right;
    }

    if (largest != i){
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size){
    while(size > 1){
        // swap first and last
        int temp = arr[1];
        arr[1] = arr[size-1];
        arr[size-1] = temp;

        // length --
        size --;

        // send to correct pos:
        heapify(arr, size, 1);
    }
}

int main(){
    MaxHeap* mheap = new MaxHeap();
    mheap->insert(50);
    cout << "inserted 50" << endl;
    mheap->insert(60);
    cout << "Inserted 60" << endl;
    mheap->insert(40);
    mheap->insert(20);
    mheap->insert(90);
    mheap->insert(10);
    mheap->insert(100);
    mheap->print();
    mheap->remove(90);
    mheap->print();

    int arr[] = {-1, 50, 60, 40, 20, 90, 10, 100};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=size/2; i>0; i--){
        heapify(arr, size, i);
    }

    for(int i : arr){
        cout << i << " ";
    }
    cout << endl;

    heapSort(arr, size);
    
    cout << "After Heap Sort: ";
    for(int i : arr){
        cout << i << " ";
    }
    cout << endl;
}