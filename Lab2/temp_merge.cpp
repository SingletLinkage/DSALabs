#include <iostream>
using namespace std;

void merge(int array[], int left, int right, int end){
	int i=left, j=right, k=0;
	int newarray[end-left+1] = {0};
	
	while ((i < right) && (j <= end)){
		if (array[i] < array[j]){
			newarray[k] = array[i];
			i++;
		}else{
			newarray[k] = array[j];
			j++;
		}
		k++;
	}
	while (i < right){
		newarray[k] = array[i];
		k++;
		i++;
	}
	while (j <= end){
		newarray[k] = array[j];
		k++;
		j++;
	}
	for (int i=left, j=0; i<=end; i++, j++){
		array[i] = newarray[j];
	}
	
}

int main(){
	int array[] = {3, 1, 5, 4};
	merge(array, 0, 1, 1);
	for(int i : array){
		cout << i << " ";
	}	
	cout << "\n";
}
