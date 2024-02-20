// Insertion sort

# include <iostream>
using namespace std;

int main(){
	int array[] = {4,23,5,345,46,4576,35,436,346};
	int len = sizeof(array)/sizeof(array[0]);
	int comparisons=0;
	int shifts = 0;

	
	for (int i=1; i<len; i++){
		int	key = array[i];
		int j=i-1;
		while (j>=0){
			if (array[j] > key){
				array[j+1] = array[j];
				shifts++;
				comparisons++;
			}else{
				comparisons++;
				break;
			}
			j--;
		}
		array[j+1] = key;
	}

	for(int i : array){
		cout << i << " ";
	}
	cout << endl;
	cout << "Comparisons: " << comparisons << " Shifts: " << shifts << endl;
	return 0;
}
