#include <stdio.h>
{
    int a[5];
    //int b[5] = {1, 2, 3, 4, 5};
    //int c[ ] = {1 ,2, 3, 4, 5};
    int d[] = {10, 2, 5, 1, 11, 2};
    int total, min;

    //writeArray(a, 5);
    //readArray(a, 5);
    //writeArray(a, 5);

    //writeArray(b, 5);
    //writeArray(c, 5);
    writeArray(d, 6);
    //writeArray(&d[2], 4);

    //printf("d = %u\n", d);
    //printf("&d[0] = %u\n", &d[0]);
    //writeArrayAddress(d, 6);

    //total = sum(d, 6);
    //printf("Total = %d\n", total);
    //printf("Minimum = %d\n", min);

    //total = sumTotal(d, 6);
    //printf("Total = %d\n", total);
    deleteFromArray(x, 10, 5);*/
    return 0;
}


void readArray(int arr[], int size)
{
    int i;
    printf("Enter %d Integers: \n", size);
    for(i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}

void writeArray(int arr[], int size)
{
    int i;
    for(i = 0; i < size; i++)
        printf("array[%d] = %d\n", i, arr[i]);
    printf("\n\n");
}

void writeArrayAddress(int arr[], int size)
{
    int i;
    for(i = 0; i < size; i++)
        printf("&array[%d] = %u\n", i,   &arr[i]);
    printf("\n\n");
}

int sum(int arr[], int size)
{
    int i, sum = 0;
    for(i = 0; i < size; i++)
        sum = sum + arr[i];
    return sum;
}
{
    int i, min = a[0];
    for(i = 1; i < size; i++)
    return min;
}


int sumTotal(int *arr, int size)
{
    int i, sum = 0;
    int *p = arr;
    for(i = 0; i < size; i++) {
        sum = sum + *p;
    return sum;
}


/*

array[0] = 2686868
array[1] = 4201470
array[2] = 4201376
array[3] = 4994280
array[4] = 39


Enter 5 Integers:
9 4 -8 -5 1
array[0] = 9
array[1] = 4
array[2] = -8
array[3] = -5
array[4] = 1


array[0] = 1
array[1] = 2
array[2] = 3
array[3] = 4
array[4] = 5


array[0] = 1
array[1] = 2
array[2] = 3
array[3] = 4
array[4] = 5


array[0] = 1
array[1] = 2
array[2] = 0
array[3] = 0
array[4] = 0


array[0] = 1
array[1] = 2
array[2] = 0
array[3] = 0
array[4] = 0


d         = 0028FECC
&d[0]     = 0028FECC
&array[0] = 0028FECC
&array[1] = 0028FED0
&array[2] = 0028FED4
&array[3] = 0028FED8
&array[4] = 0028FEDC


Total = 3
Total = 3

*/