#include <stdio.h>

int main() {
	int x[4], y[4], d[3];
	int i = 0;
	printf("Enter the coordinates of the point and after than enter coordinates of three vertices of triangle\n");
	for (i = 0; i <= 3; i++) {
        scanf("%d %d", &x[i], &y[i]);
	}
	d[0] = (x[1] - x[0]) * (y[2] - y[0]) - (x[2] - x[0]) * (y[1] - y[0]);
	d[1] = (x[2] - x[0]) * (y[3] - y[0]) - (x[3] - x[0]) * (y[2] - y[0]);
	d[2] = (x[3] - x[0]) * (y[1] - y[0]) - (x[1] - x[0]) * (y[3] - y[0]);
	if (d[0]*d[1] > 0) {
		if (d[1]*d[2] > 0) {
			printf("yes");
		}
		else {
			printf("no");
		}
	}
	else {
		printf("no");
	}
	return 0;
}
