#include <stdio.h>
#include <stdlib.h>

// Function to partition the array
int partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int tmp;
    int j = low;
    while(j < high)
    {
        if (array[j] < pivot)
        {
            i++;
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
        j++;
    }
    tmp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = tmp;
    printf("pivo index ==> %d\n", i + 1);
    return (i + 1); // Return the pivot index
}

// Quick sort function
void quick_sort(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(array, low, high);
        quick_sort(array, low, pivot_index - 1);  // Sort the left side
        quick_sort(array, pivot_index + 1, high); // Sort the right side
    }
}

// Main function to test quick sort
int main()
{
    int array[10] = {15, 7, 2, 0, -4, 6, 10, 1, 5, 9};
    int size = 10;

    quick_sort(array, 0, size - 1);

    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");

    return (0);
}
