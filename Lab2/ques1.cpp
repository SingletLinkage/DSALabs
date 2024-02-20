// Insertion sort

# include <iostream>
using namespace std;


int main(){
	int array[INT16_MAX];
	int len;
	
	cout << "Enter number of elements: ";
	cin >> len;

	for (int i=0; i<len; i++){
		cout << "Enter element number " << i+1 << ": ";
		cin >> array[i];
	}

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

	for(int i=0; i<len; i++){
		cout << array[i] << " ";
	}
	cout << endl;
	cout << "Comparisons: " << comparisons << " Shifts: " << shifts << endl;
	return 0;
}
