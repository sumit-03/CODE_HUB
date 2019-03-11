#include "stdio.h"
#include "stdlib.h"
#include "math.h"

void print(int *a, int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%5d", a[i]);
	printf("\n");
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a   = *b;
	*b   = temp;
}

void bubblesort(int *a, int n)
{
	int i,j,flag = 0;
	for(i = 0; flag == 0 && i < n-1; i++) {
		flag = 1; // No Swap i.e. array is sorted
		for(j = 0; j <= n-i-2; j++) {
			if(a[j] > a[j+1]) {
				swap(&a[j], &a[j+1]);
				flag = 0; // At least one swap
			}
		}
	}
}

void selectionsort(int *a, int n)
{
	int i,j,min;
	for(i = 0; i < n-1; i++) {
		min = i;
		for(j = i+1; j < n; j++) {
			if(a[j] < a[min])
				min = j;
		}
		swap(&a[i],&a[min]);
	}
}

void insertionsort(int *a, int n)
{
	int i,j,key;
	for(i = 1; i < n; i++) {
		key = a[i];
		j = i-1;
		while(j > -1 && a[j] > key) {
			a[j+1] = a[j];
			j = j-1;
		}
		a[j+1] = key;
	}
}

void merge(int *a, int low, int mid, int high)
{
	int i = low, j = mid+1, k = 0;

	int b[high-low+1];


	while(i <= mid && j <= high) {
		if(a[i] <= a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}

    while(j != high+1)
        b[k++] = a[j++];
    while(i != mid+1)
        b[k++] = a[i++];


	for(i = low, j = 0; i <= high; i++, j++)
		a[i] = b[j];
}

void mergesort(int *a, int low, int high)
{
	if(low < high) {
		int mid = (high+low)/2;
		mergesort(a, low, mid);
		mergesort(a, mid+1, high);
		merge(a, low, mid, high);
	}
}

int partition(int *a, int low, int high)
{
	int i,j;
	i = low-1;
	for(j = low; j < high; j++) {
		if(a[j] < a[high]) {
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[high]);
	return i+1;
}

void quicksort(int *a, int low, int high)
{
	if(low < high) {
		int pivot = partition(a, low, high);
		quicksort(a, low, pivot-1);
		quicksort(a, pivot+1, high);
	}
}

void linearsearch(int *a, int n, int key)
{
	int i,flag = 0;
	for(i = 0; i < n; i++) {
		if(a[i] == key) {
			flag = 1;
			printf("\n%d is found at index %d.", key, i);
		}
	}
	if(flag == 0)
		printf("\n%d is not found.", key);
	printf("\n");
}

void binarysearch(int *a, int n, int key)
{
	int low,high,mid,i,flag;

	flag = 0;
	low = 0;
	high = n-1;

	while(low < high+1) {
		mid = (low+high)/2;
		if(a[mid] == key) {
			flag = 1;
			i = mid;
			while(i >= 0 && a[mid] == a[i]) {
				i--;
			}
			i++;
			mid = i;
			while(i < n && a[mid] == a[i]) {
				printf("\n%d is found at index %d.", key, i);
				i++;
			}
			break;
		}
		else if(a[mid] > key)
			high = mid-1;
		else
			low = mid+1;
	}
	if(flag == 0)
		printf("\n%d is not found.", key);
	printf("\n");
}

int main()
{
	int *a = NULL;
	int n,key,i,choice;

	while(1) {
		printf("EXIT           : 0\n");
		printf("BUBBLE SORT    : 1\n");
		printf("SELECTION SORT : 2\n");
		printf("INSERTION SORT : 3\n");
		printf("MERGE SORT     : 4\n");
		printf("QUICK SORT     : 5\n");
		printf("LINEAR SEARCH  : 6\n");
		printf("BINARY SEARCH  : 7\n");
		scanf("%d", &choice);

		if(choice == 0)
			exit(0);

		printf("How many numbers:\n");
		scanf("%d", &n);

		a = (int *)calloc(n,sizeof(int));
		for(i = 0; i < n; i++) {
			printf("a[%d] = ", i);
			scanf("%d",&a[i]);
		}
		if(choice >= 1 && choice <= 5) {
			printf("The array before sorting:\n");
			print(a, n);
		}
		if(choice >= 6 && choice <= 7) {
			printf("Enter the key to be searched:\n");
			scanf("%d", &key);
			printf("The array before searching:\n");
			print(a, n);
		}

		switch(choice) {
			case 1:
				bubblesort(a,n);
				break;
			case 2:
				selectionsort(a,n);
				break;
			case 3:
				insertionsort(a,n);
				break;
			case 4:
				mergesort(a,0,n-1);
				break;
			case 5:
				quicksort(a,0,n-1);
				break;
			case 6:
				linearsearch(a,n,key);
				break;
			case 7:
				binarysearch(a,n,key);
				break;
			default:
				printf("You have made a wrong choice\n.");
		}
		if(choice >= 1 && choice <= 5) {
			printf("The array after sorting:\n");
			print(a, n);
		}
		if(a != NULL) {
			free(a);
			a = NULL;
		}
	}
	return 0;
}
