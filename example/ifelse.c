#include <stdio.h>
int main(void){
	int a,b;
	printf("Enter first number: ");
	scanf("%d", &a);
	printf("Enter second number: ");
	scanf("%d", &b);

	if (a>b){
		printf("%d is greater", a);
	}else{
		printf("%d is greater", b);
	}
}
