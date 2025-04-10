#include <stdio.h>

typedef enum {
    ASCENDING,
    DESCENDING
} SortOrder;

void QuickSortArray(int* arr, int size, SortOrder sortOrder);

int main() {
    int arr[] = { 5, 2, 9, 1, 5, 6, 3, 7, 8, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);

    QuickSortArray(arr, size, DESCENDING);

    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    return 0;
}

void QuickSortArray(int* arr, int size, SortOrder sortOrder) {
    if (size < 2) {
        return;
    }

    int pivot = *(arr + (size / 2)); // pivot used for partitioning
    int left = 0;                    // left index (this is the first element of the array)
    int right = size - 1;            // right index (this is the last element of the array)

    while (left <= right) { // while the left index is less than or equal to the right index (this means we have elements to sort)
        while ((sortOrder == ASCENDING ? *(arr + left) < pivot : *(arr + left) > pivot)) { // if the left element is less than the pivot or greater than the pivot
            left++; // increment the left index, this will move the left index to the right
        }

        while ((sortOrder == ASCENDING ? *(arr + right) > pivot : *(arr + right) < pivot)) { // if the right element is greater than the pivot or less than the pivot
            right--; // decrement the right index, this will move the right index to the left
        }

        if (left <= right) { // if the left index is less than or equal to the right index, which means we have elements to swap
            int temp = *(arr + left); // store the left element in a temporary variable
            *(arr + left) = *(arr + right); // swap the left element with the right element
            *(arr + right) = temp; // store the temporary variable in the right element
            left++; // increment the left index, this will move the left index to the right
            right--; // decrement the right index, this will move the right index to the left
        }
    }

    QuickSortArray(arr, right + 1, sortOrder); // sort the left partition, this will sort the elements to the left of the pivot
    QuickSortArray(arr + left, size - left, sortOrder); // sort the right partition, this will sort the elements to the right of the pivot
}
