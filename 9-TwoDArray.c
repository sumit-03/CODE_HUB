#include <stdio.h>

void readArray(int r, int c, int a[][c])
{
	int i, j;
	for(i = 0; i < r; i++)
		for(j = 0; j < c; j++)
			scanf("%d", &a[i][j]);
}

void writeArray(int r, int c, int a[][c])
{
	int i, j;

	printf("\nMatrix\n");

	for(i = 0; i < r; i++) {
		for(j = 0; j < c; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
}

void AddMatrices(int r, int c, int a[][c], int b[][c], int res[][c])
{
	int i, j;
	for(i = 0; i < r; i++)
		for(j = 0; j < c; j++)
			res[i][j] = a[i][j] + b[i][j];

	printf("\nMatrix Addition\n");

	for(i = 0; i < r; i++) {
		for(j = 0; j < c; j++)
			printf("%4d", res[i][j]);
		printf("\n");
	}
}

void Transpose(int r, int c, int a[][c], int res[][r])
{
	int i, j;
	for(i = 0; i < r; i++)
		for(j = 0; j < c; j++)
			res[j][i] = a[i][j];

	printf("\nMatrix Transpose\n");

	for(i = 0; i < c; i++) {
		for(j = 0; j < r; j++)
			printf("%4d", res[i][j]);
		printf("\n");
	}
}

void MulMatrices(int r1, int c1, int a[][c1], int r2, int c2, int b[][c2], int res[][c2])
{
	int i, j, k;
	if (c1 != r2) {
        printf("Matrix Multiplication is not possible.\n");
        return;
    }
	for(i = 0; i < r1; i++)
		for(j = 0; j < c2; j++) {
			res[i][j] = 0;
			for(k = 0; k < c1; k++)
				res[i][j] += a[i][k] * b[k][j];
		}

	printf("\nMatrix Multiplication\n");

	for(i = 0; i < r1; i++) {
		for(j = 0; j < c2; j++)
			printf("%4d", res[i][j]);
		printf("\n");
	}
}


int main()
{
	int a[3][4];
	int b[][4] = { {1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}};

	int resTrans[4][3];
	int resAdd[3][4];
	int resMul[3][3];

	readArray(3, 4, a);
	writeArray(3, 4, a);
	writeArray(3, 4, b);

	AddMatrices(3, 4, a, b, resAdd);
	Transpose(3, 4, a, resTrans);
	MulMatrices(3, 4, a, 4, 3, resTrans, resMul);

	return 0;
}
