/*
Zak Rawles
5341679
3/8/24
COP3502C-0040
Lab Assignment 7 (bubble and selection sort)

program uses sort algorithms to sort two arrays. bubble sort is used and selection sort is used.
these print the number of times and element is swapped in the sort and total swaps for the algorithm.
*/



#include <stdio.h>

// function to swap the position of two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

//implement a bubble sort for array 1 and 2
void bubbleSort(int arr[], int n, int *total_swaps, int swapCount[]) {
    int i, j, temp, swaps;
    for (i = 0; i < n-1; i++) {
        swaps = 0;
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps++;
                (*total_swaps)++;
                swapCount[arr[j]]++;
                swapCount[arr[j+1]]++;
            }
        }
        if (swaps == 0) break;
    }
}

//implement a selection sort for array 3 and 4 (same as array 1 and 2 originally)
void selectionSort(int arr[], int n, int *total_swaps, int swapCount[]) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&arr[i], &arr[min_idx]);
            (*total_swaps)++;
            swapCount[arr[i]]++;
            swapCount[arr[min_idx]]++;
        }
    }
}



int main() {
    //used 4 array, both are the same set but array 3 and 4 are like a reset so selection sort can sort
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int array3[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array4[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    //swap counts
    int swapsBubble1 = 0, swapsBubble2 = 0, swapsSelection1 = 0, swapsSelection2 = 0;
    int swapCount1[100] = {0}; 
    int swapCount2[100] = {0}; 
    int swapCount3[100] = {0}; 
    int swapCount4[100] = {0}; 

    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);

    //running sort algos
    bubbleSort(array1, n1, &swapsBubble1, swapCount1);
    bubbleSort(array2, n2, &swapsBubble2, swapCount2);
    selectionSort(array3, n1, &swapsSelection1, swapCount3);
    selectionSort(array4, n2, &swapsSelection2, swapCount4);

    //print requires statments and total swaps
    printf("array1:\n");
    for (int i = 0; i < n1; i++) {
        printf("%d: %d of times %d is swapped\n", array1[i], swapCount1[array1[i]], array1[i]);
    }
    printf("%d\n\n", swapsBubble1);

    printf("array2:\n");
    for (int i = 0; i < n2; i++) {
        printf("%d: %d of times %d is swapped\n", array2[i], swapCount2[array2[i]],array2[i]);
    }
    printf("%d\n\n", swapsBubble2);

    printf("array1:\n");
    for (int i = 0; i < n1; i++) {
        printf("%d: %d of times %d is swapped\n", array3[i], swapCount3[array3[i]], array3[i]);
    }
    printf("%d\n\n", swapsSelection1);

    printf("array2:\n");
    for (int i = 0; i < n2; i++) {
        printf("%d: %d of times %d is swapped\n", array4[i], swapCount4[array4[i]], array4[i]);
    }
    printf("%d\n", swapsSelection2);

    return 0;
}
