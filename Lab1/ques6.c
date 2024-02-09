#include <stdio.h>
#include <string.h>

int main(void){
	const int MAX_SIZE = 200;
	int flag=0;
	char str[MAX_SIZE];
	printf("Enter string: ");
	fgets(str, MAX_SIZE, stdin);
	int length = strlen(str);

	char rev_str[length-1];

	for (int i=0; i<length-1; i++){
		//printf("%c\n", str[length-i-1]);
		rev_str[i] = str[length-2-i];
	}
	printf("Reversed String is: ");
	for (int i=0; i<length-1; i++){
		printf("%c", rev_str[i]);
		if (rev_str[i] != str[i]){
			flag = 1;
		}
	}
	printf("\n");
	if (flag == 1){
		printf("The Given string is not Palindrome\n");
	}else{
		printf("The Given string is Palindrome\n");
	}
	return 0;
}
