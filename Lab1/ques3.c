#include <stdio.h>

int calculateArea(int length, int width){
	printf("Area of the rectangle is: %d\n", length*width);
}

int calculatePerimeter(int length, int width){
	printf("Perimeter of the rectangle is: %d\n", 2*(length+width));
}

int main(void){
	int length=0, width=0;
	while (length<=0){
		printf("Enter Length: ");
		scanf("%d", &length);
		if (length<=0){
			printf("Length has to be positive...\n");
		}
	}

	while (width<=0){
		printf("Enter Width: ");
		scanf("%d", &width);
		if (width<=0){
			printf("Width has to be positive...\n");
		}
	}

	calculatePerimeter(length, width);
	calculateArea(length, width);
	return 0;
}
