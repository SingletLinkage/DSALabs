#include <stdio.h>
#define PI 3.14159265358979323846

int calculateVolume(int radius, int height){
	printf("Volume of cylinder is: %.2f\n", PI*radius*radius*height);
}

int calculateSurfaceArea(int radius, int height){
	printf("Surface Area of Cylinder is: %.2f\n", 2*PI*radius*height);
}

int main(void){
	int height=0, radius=0;
	while (radius<=0){
		printf("Enter Radius: ");
		scanf("%d", &radius);
		if (radius<=0){
			printf("Radius has to be positive...\n");
		}
	}

	while (height<=0){
		printf("Enter Height: ");
		scanf("%d", &height);
		if (height<=0){
			printf("Height has to be positive...\n");
		}
	}

	calculateVolume(radius, height);
	calculateSurfaceArea(radius, height);
	
	return 0;
}
