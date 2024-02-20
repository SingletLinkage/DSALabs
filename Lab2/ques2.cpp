// Merge Sort 
#include <iostream>
using namespace std;
int comparisons=0, shifts=0;

void merge(int array[], int left, int right, int end){
	int i=left, j=right, k=0;
	int newarray[end-left+1] = {0};
	
	while ((i < right) && (j <= end)){
		comparisons += 3;
		if (array[i] < array[j]){
			newarray[k] = array[i];
			shifts ++;
			i++;
		}else{
			newarray[k] = array[j];
			shifts ++;
			j++;
		}
		k++;
	}
	
	while (i < right){
		comparisons ++;
		newarray[k] = array[i];
		shifts ++;
		k++;
		i++;
	}
	
	while (j <= end){
		comparisons ++;
		newarray[k] = array[j];
		shifts ++;
		k++;
		j++;
	}
	
	for (int i=left, j=0; i<=end; i++, j++){
		comparisons ++;
		array[i] = newarray[j];
		shifts ++;
	}
	
	comparisons += 4;
	
}

void mergeSort(int array[], int left, int right){
	comparisons++;
	if (right > left){
		int mid = (left + right)/2;
		mergeSort(array, left, mid);
		mergeSort(array, mid+1, right);
		merge(array, left, mid+1, right);
	}
}



int main(){
	int array[] = {1,3,5,4,9,2,5,2,7,9,7,0};
	int len = sizeof(array)/sizeof(array[0]);

	mergeSort(array, 0, len-1);
		
	for (int i : array){
		cout << i << " ";
	}
	cout << endl;

	cout << "Comparisons: " << comparisons << " and Shifts: " << shifts << "\n";
	
	return 0;
}
