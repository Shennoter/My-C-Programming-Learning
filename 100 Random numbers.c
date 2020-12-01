#include<stdio.h>
#include<stdlib.h>
int main() {
	float arr[100];
	for (int i = 0; i <= 99; i++) {
		arr[i] = rand();
	}
	float min=arr[0], max=arr[0],sum=0;
	for (int i = 0; i <= 99; i++) {
		if (max >= arr[i]) {
			max = arr[i];
		}
		if (min <= arr[i]) {
			min = arr[i];
		}
	}
	for (int i = 0; i <= 99; i++) {
		sum += arr[i];
	}
	printf("%f %f %f", min, max, sum / 100);
	return 0;
}