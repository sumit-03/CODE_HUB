#include <stdio.h>
#include <stdlib.h>

#define ROWSIZE 4
#define COLSIZE 5


void f1()
{
	int i, n;
	int *b = NULL;

	printf("Enter n: ");
	scanf("%d", &n);
	b = (int *)malloc(n * sizeof(int));

	printf("\nBefore Initialization: Initialized to Garbage Value\n");
	for(i = 0; i < n; i++)
		printf("%10d", b[i]);

	printf("\nEnter %d values\n", n);
	for(i = 0; i < n; i++)
		scanf("%d", &b[i]);

	printf("\nAfter Initialization\n");
	for(i = 0; i < n; i++)
		printf("%10d", b[i]);
	printf("\n");
	free(b);
}

void f2()
{
	int i, n;
	int *a = NULL;

	printf("Enter n: ");
	scanf("%d", &n);
	a = (int *)calloc(n, sizeof(int));

	printf("\nBefore Initialization: Initialized to Zero\n");
	for(i = 0; i < n; i++)
		printf("%10d", a[i]);

	printf("\nEnter %d values\n", n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);

	printf("\nAfter Initialization\n");
	for(i = 0; i < n; i++)
		printf("%10d", a[i]);
	printf("\n");
	free(a);
}

void f3()
{
	int i, j;
	int A[ROWSIZE][COLSIZE];
	int (*B)[COLSIZE];
	int *C[ROWSIZE];
	int **D;
	printf("\nArray A\n");
	printf("sizeof(A) = %d\nsizeof(*A) = %d\nsizeof(**A) = %d\n", sizeof(A), sizeof(*A), sizeof(**A));

	for (i = 0; i < ROWSIZE; i++)
        for(j = 0; j < COLSIZE; j++)
            A[i][j] = i*COLSIZE + j;

    for (i = 0; i < ROWSIZE; i++) {
        for(j = 0; j < COLSIZE; j++)
            printf("%4d", A[i][j]);
        printf("\n");
    }

	/* A is a static array and cannot be free'd */


	printf("\nArray B\n");
	B = (int (*)[COLSIZE])calloc(ROWSIZE, sizeof(int[COLSIZE]));
	printf("sizeof(B) = %d\nsizeof(*B) = %d\nsizeof(**B) = %d\n", sizeof(B), sizeof(*B), sizeof(**B));

    for (i = 0; i < ROWSIZE; i++)
        for(j = 0; j < COLSIZE; j++)
            B[i][j] = i*COLSIZE + j;

    for (i = 0; i < ROWSIZE; i++) {
        for(j = 0; j < COLSIZE; j++)
            printf("%4d", B[i][j]);
        printf("\n");
    }
	/* B is a single pointer */
	free(B);


	printf("\nArray C\n");
	for (i = 0; i < ROWSIZE; i++)
		C[i] = (int *)calloc(COLSIZE, sizeof(int));
	printf("sizeof(C) = %d\nsizeof(*C) = %d\nsizeof(**C) = %d\n", sizeof(C), sizeof(*C), sizeof(**C));

    for (i = 0; i < ROWSIZE; i++)
        for(j = 0; j < COLSIZE; j++)
            C[i][j] = i*COLSIZE + j;

    for (i = 0; i < ROWSIZE; i++) {
        for(j = 0; j < COLSIZE; j++)
            printf("%4d", C[i][j]);
        printf("\n");
    }

	/* C is a static array of pointers each to be free'd individually */
	for (i = 0; i < ROWSIZE; i++)
        free(C[i]);  /* Free each row */


	printf("\nArray D\n");
	D = (int **)calloc(ROWSIZE, sizeof(int *));
	for (i = 0; i < ROWSIZE; i++)
		D[i] = (int *)calloc(COLSIZE, sizeof(int));
	printf("sizeof(D) = %d\nsizeof(*D) = %d\nsizeof(**D) = %d\n", sizeof(D), sizeof(*D), sizeof(**D));

	for (i = 0; i < ROWSIZE; i++)
        for(j = 0; j < COLSIZE; j++)
            D[i][j] = i*COLSIZE + j;

    for (i = 0; i < ROWSIZE; i++) {
        for(j = 0; j < COLSIZE; j++)
            printf("%4d", D[i][j]);
        printf("\n");
    }

	/* D is a pointer to pointers. Each of these pointers is to be free'd */
	for (i =  0; i< ROWSIZE; i++)
		free(D[i]);  /* Free each row */
	free(D);                               /* Free the row top */
}


int main()
{
	f1();
	f2();
	f3();
	return 0;
}
