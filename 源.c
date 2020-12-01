#include<stdio.h>
int main()
{
	int a, d;
	for (a=1; a <= 20; a++) {
		for (d=1; d <= 20; d++) {
			if ((4 * a + 6 * d == 26) && (a * (a + d) * (a + 2 * d) * (a + 3 * d)) == 880) {
				for (int i = 1; i <= 20; i++) {
					printf("%d ", a);
					a += d;
					if (i % 5 == 0) {
						printf("\n");
					}

				}
			}
		}
	}
	return 0;
}