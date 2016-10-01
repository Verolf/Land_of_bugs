#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int lhs, int rhs) {
	int tmp = a[lhs];
	a[lhs] = a[rhs];
	a[rhs] = tmp;
}

void insertion_sort(int* a, int n) {
	int i;
	for (i = 1; i < n; ++i) {
		int j = i;
		while (j > 0 && a[j - 1] > a[j]) { // push current to the left
			swap(a, j - 1, j);
			j--;
		}
	}
}

int main() {
	int* a;
	int n, i;
	scanf("%d ", &n);
	a = (int *)malloc(n*sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);	
	}
	printf("\n");
	insertion_sort(a, n);
	
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);	
	}
	return 0;		
}
