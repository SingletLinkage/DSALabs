#include <stdio.h>

int main(void){
	const int MAX_SIZE = 1000;
	char string[MAX_SIZE];
	char words[MAX_SIZE][MAX_SIZE];
	char letter;
	int w_idx=0, l_idx=0;

	printf("Enter the string: ");
	fgets(string, MAX_SIZE, stdin);

	for(int i=0; i<MAX_SIZE; i++){
		letter = string[i];
		if (letter == '\n'){
			break;
		}
		if (letter == ' '){
			words[w_idx][l_idx] = '\0';
			w_idx += 1;
			l_idx = 0;
			continue;
		}
		words[w_idx][l_idx] = letter;
		l_idx += 1;
	}

	for (int x=0; x<=w_idx; x++){
		for (int y=0;;y++){
			if (words[x][y] == '\0'){
				break;
			}
			printf("%c", words[x][y]);
		}
		printf("\n");
	}
	
	return 0;
}
