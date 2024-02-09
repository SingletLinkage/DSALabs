#include <stdio.h>

int main(void){
	long long int days;
	printf("Enter days: ");
	scanf("%lld", &days);

	long int years;
	int  months;

	years = days / 365;
	days = days % 365;
	months = days / 30;
	days = days % 30;

	printf("Years: %ld\nMonths: %d\nDays: %lld\n", years, months, days);

	if ((years%100) == 0){
		if ((years%400) == 0){
			printf("Leap Year\n");
		}else{
			printf("Not a leap Year\n");
		}
	}else{
		if ((years%4)==0){
			printf("Leap Year\n");
		}else{
			printf("Not a Leap Year\n");
		}
	}
}
