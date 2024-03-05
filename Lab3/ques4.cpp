#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    int row;
    int col;
    Node* next;

    Node(int data, int row, int col){
        this->data = data;
        this->row = row;
        this->col = col;
        this->next = NULL;
    }
};

class SLL{
    public:
    Node* top;

    SLL(){
        this->top = NULL;
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

    void push(Node* newNode){
        newNode->next = top;
        top = newNode;
    }

    void display(){
        if (top == NULL ){
            cout << "Stack Underflow" << endl;
            exit(1);
        }

        Node* temp = top;
        while (temp != NULL){
            cout << "( data: " << temp->data << " At: " << temp->row << ", " << temp->col << " )  ";
            temp = temp -> next;
        }
        cout << endl;
    }
};

int A[5][6] = {
                {1 , 1 , 1 , 1 , 1 , 1 },
                {0 , 8 , 0 , 0 , 0 , 0 },
                {4 , 0 , 0 , 2 , 0 , 0 },
                {0 , 0 , 0 , 0 , 0 , 5 },
                {0 , 0 , 2 , 0 , 0 , 0 }};
 
 
int B[5][6] = { 
                {0 , 0 , 0 , 0 , 1 , 0 },
                {0 , 5 , 0 , 2 , 0 , 0 },
                {0 , 0 , 1 , 0 , 0 , 5 },
                {2 , 8 , 0 , 0 , 1 , 0 },
                {0 , 0 , 4 , 0 , 0 , 0 }};

void print(int matrix[][5], int rows, int cols){
    for (int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void printMatrix(SLL** matrix, int rows){
    for (int i=0; i<rows; i++){
        matrix[i] -> display();
    }
}

int main(){

    // dense matrix multiplication
    int prod[5][5];

    for (int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            int sum=0;
            for(int k=0; k<6; k++){
                sum += A[i][k] * B[j][k];
            }
            prod[i][j] = sum;
        }
    }
    cout << "Dense Matrix Multiplication: \n";
    print(prod, 5, 5);

    // sparse matrix generation
    SLL* matrixA[5];
    SLL* matrixB[5];

    for(int i=0; i<5; i++){
        matrixA[i] = new SLL();
        for (int j=0; j<6; j++){
            if (A[i][j] != 0){
                Node* newNode = new Node(A[i][j], i, j);
                matrixA[i] -> push(newNode);
            }
        }
    }
    for(int i=0; i<5; i++){
        matrixB[i] = new SLL();
        for (int j=0; j<6; j++){
            if (B[i][j] != 0){
                Node* newNode = new Node(B[i][j], i, j);
                matrixB[i] -> push(newNode);
            }
        }
    }
    cout << "Sparse Matrix A: \n";
    printMatrix(matrixA, 5);
    cout << "Sparse Matrix B: \n";
    printMatrix(matrixB, 5);


    // Sparse Matrix Multiplication
    SLL* prodMatrix[5];
    for(int i=0; i<5; i++){
        prodMatrix[i] = new SLL();
    }

    for(int i=0; i<5; i++){
        SLL* rowA = matrixA[i];

        for(int j=0; j<5; j++){

            SLL* colB = matrixB[j];
            int sum=0;
            Node* headA = rowA->top;

            while(headA != NULL){
                Node* headB = colB->top;

                while(headB != NULL){
                    if (headA->col == headB->col){
                        sum += (headA->data * headB->data);
                    }
                    headB = headB->next;
                }
                headA = headA->next;
            }
            if (sum != 0){
                Node* prodNode = new Node(sum, i, j);
                prodMatrix[i] -> push(prodNode);
            }

        }
    }
    cout << "Product Sparse Matrix: \n";
    printMatrix(prodMatrix, 5);

    return 0;
}