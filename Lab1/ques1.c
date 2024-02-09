#include <stdio.h>
int main(void){
	// generate GCD of two nums
	/*
	GCD(A,B) = GCD(B,R) for A = B*Q + R
	*/
	int a=0, b=0;
	while (a<=0){
		printf("Enter number A: ");
		scanf("%d", &a);
		if (a<=0){
			printf("Enter Positive number please...\n");
		}
	}
	
	while (b<=0){
		printf("Enter number B: ");
		scanf("%d", &b);
		if (b<=0){
			printf("Enter Positive number please...\n");
		}
	}

	while ((a!=0)&&(b!=0)){
		int rem = a%b;
		a = b;
		b = rem;
	}

	printf("GCD = %d\n", a);
}
