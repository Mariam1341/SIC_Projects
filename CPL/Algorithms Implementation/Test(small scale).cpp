#include<stdio.h>
#include<stdlib.h>
#include<time.h>
const int num  = 20;
int arr[num]; 
int n = sizeof(arr) / sizeof(arr[0]);
//Function to sort an array using insertion sort 
void insertionSort(int arr[], int n)
{
	int key, j;                
	for (int i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)  //shifting the element of array towords right if are greater than key
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
 
// Function to swap two elements 
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
// Function to place the pivot element at its correct position in the sorted array (smaller elements < pivot < greater elements) 
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high]; 
    int i = (low - 1);  
    for (int j = low; j <= high - 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++; 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
// Function that implements QuickSort as low => Starting index, high => Ending index 
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
  
// Function to print the array 
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ",arr[i]);
} 
// Function to fill the array with random numbers
void random_array (){
	for (int i =0; i < num; i++)
		{
			arr[i] =  rand()%num;	
		}
}
  
int main()
{       
        float start_1, end_1, start_2, end_2, time_1, time_2;
        // To check insertion sort in this implementation can't notice the time that insertion take 
        random_array ();
	    start_1 = clock();
	    printf("\nThe random array: ");
	    printArray(arr,n);
		insertionSort(arr, n);
		end_1 = clock();
		time_1 = (end_1-start_1);
	//	printf("\nThe array is sorted using insertion sort in %f seconds", time_1);
		printf("\nThe sorted array: ");
		printArray(arr,n);
		
		// To check quick sort in this implementation can't notice the time that insertion take 
		random_array ();
    	start_2 = clock();
    	printf("\n\nThe random array: ");
    	printArray(arr,n);
		quickSort(arr, 0, n - 1); 
		end_2 = clock();
		time_2 = (end_2 - start_2);
	//	printf("\nThe array is sorted using quick sort in %f seconds", time_2);
		printf("\nThe sorted array: ");
		printArray(arr,n);

	return 0;

}
