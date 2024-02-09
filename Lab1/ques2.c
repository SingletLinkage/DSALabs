#include <stdio.h>

void generateFibonacci(int n){
	int a = 1;
	int b = 1;
	if (n==1) printf("%d\n", a);
	else printf("%d\n%d\n", a, b);
	n = n-2;

	while(n>0){
		n--;
		a = a+b;
		b = a-b;
		printf("%d\n", a);
	}
}

int main(void){
	int userInput = -1;
	while (userInput <= 0){
		printf("Enter the number of Terms: ");
		scanf("%d", &userInput);
		if (userInput <= 0){
			printf("Please input positive numbers only...\n");
		}
	}
	generateFibonacci(userInput);
	return 0;
}
