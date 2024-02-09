#include <stdio.h>
#include <stdlib.h>
int main(void){
	int a,b;
	printf("Enter first number: ");
	scanf("%d", &a);
	printf("Enter second number: ");
	scanf("%d", &b);

	int ch;
	printf("Enter: \n1: Addition\n2: Subtraction\n3: Multiplication\n4: Division\n");
	scanf("%d", &ch);

	switch(ch){
		case 1:
			printf("Addition: %d\n", a+b);
			break;
		case 2:
			printf("Subtraction: %d\n", a-b);
			break;
		case 3:
			printf("Multiplication: %d\n", a*b);
			break;
		case 4:
			printf("Division: %d\n", a/b);
			break;
		default:
			printf("get good");
			exit(0);
	}

}
