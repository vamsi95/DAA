#include <stdio.h>

int getFirstElement(int arr[], int size) {
    // Constant time operation
    if (size == 0)
        return -1;  // return -1 for empty array
    return arr[0];
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("First element: %d\n", getFirstElement(arr, size));
    return 0;
}
