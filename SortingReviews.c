#include<stdio.h>
#include<stdlib.h>

//int arr[] = {3,5,2,9,1,10,100};
//printf("Size of array: %d", sizeof(arr)/sizeof(arr[1]));
void selectionSort();
void insertionSort();
void bubbleSort();
void doQuickSort();
void quickSort(int arr[], int low, int high);
int main()
{
	
	selectionSort();
	insertionSort();
	bubbleSort();
	doQuickSort();
	return 0;
}

void selectionSort()
{
	int arr[] = {3,5,2,9,1,10,100};
	int size = sizeof(arr)/sizeof(arr[1]);
	int x, y, min_idx, temp;
	
	printf("Unsorted Array: ");
	for(x=0;x<size;x++){
		printf("%d ", arr[x]);
	}
	
	for(x=0;x<size;x++){
		min_idx = x;
		for(y=x+1;y<size;y++){
			if(arr[y]<arr[min_idx]){
				min_idx=y;
			}
		}
		temp = arr[x];
		arr[x]=arr[min_idx];
		arr[min_idx] = temp;
	}
	printf("\nSelectionSort: ");
	for(x=0;x<size;x++){
		printf("%d ", arr[x]);
	}
}

void insertionSort()
{
	int arr[] = {3,5,2,9,1,10,123,78};
	int size = sizeof(arr)/sizeof(arr[1]);
	int x, y, key;
	
	printf("\n\nUnsorted Array: ");
	for(x=0;x<size;x++){
		printf("%d ", arr[x]);
	}
	
	for(x = 1; x<size;x++){
		key = arr[x];
		for(y=x-1;y>=0 && arr[y]>key;y--){
			arr[y+1]=arr[y];
		}
		arr[y+1] = key;
	}
	
	printf("\nInsertionSort: ");
	for(x=0;x<size;x++){
		printf("%d ", arr[x]);
	}
}

void bubbleSort()
{
	int arr[] = {3,5,2,9,1,10,123,78};
	int size = sizeof(arr)/sizeof(arr[1]);
	int x, y, swap;
	
	printf("\n\nUnsorted Array: ");
	for(x=0;x<size;x++){
		printf("%d ", arr[x]);
	}
	
	for(x=0;x<size;x++){
		for(y=0;y<size-x-1;y++){
			if(arr[y]>arr[y+1]){
				swap = arr[y+1];
				arr[y+1] = arr[y];
				arr[y] = swap;
			}
		}
	}
	
	printf("\nBubbleSort: ");
	for(x=0;x<size;x++){
		printf("%d ", arr[x]);
	}
}

void doQuickSort()
{
	int arr[] = {3,5,2,9,1,10,123,78};
	int size = sizeof(arr)/sizeof(arr[1]);
	int x, y, swap;
	
	printf("\n\nUnsorted Array: ");
	for(x=0;x<size;x++){
		printf("%d ", arr[x]);
	}
	
	quickSort(arr, 0, size-1);
	
	printf("\nQuickSort: ");
	for(x=0;x<size;x++){
		printf("%d ", arr[x]);
	}
}

void quickSort(int arr[], int low, int high)
{
	if(low<high){
		int pi = partition(arr, low, high);
		
		quickSort(arr, low, pi-1);
		quickSort(arr, pi+1, high);
	}
}


int partition (int arr[], int low, int high)
{
    int pivot = arr[high];   
    int i = (low - 1); 
 	int j, temp;
    for (j = low; j <= high- 1; j++){
        if (arr[j] <= pivot){
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

