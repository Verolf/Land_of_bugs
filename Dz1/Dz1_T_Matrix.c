#include <stdio.h>
#include <stdlib.h>

int main() {
	int m, n, i, k;
	scanf("%d %d", &m, &n);
	int **f;
	f = (int **)malloc(m*sizeof(int*));
	for (i = 0; i < n; i++) {
		f[i] = (int*)malloc(n*sizeof(int));	
	}
	
	for (i = 0; i < m; i++) {
		for (k = 0; k < n; k++) {
			scanf("%d", &f[i][k]);
		}
	}
	printf("\n");
	for (i = 0; i < m; i++) {
		for (k = 0; k < n; k++) {
			printf("%d ", f[k][i]);
		}
		printf("\n");
	}
	
	for (i = 0; i < m; i++) {
		free(f[i]);
	}
	free(f);
	return 0;
}
