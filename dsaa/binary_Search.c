#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target is greater, ignore left half
        if (arr[mid] < target)
            left = mid + 1;

        // If target is smaller, ignore right half
        else
            right = mid - 1;
    }

    // If target is not present in array
    return -1;
}

// Driver program
int main() {

    int n;
    printf("entersize of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("enter array : ");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    int target;
    printf("enter target : ");
    scanf("%d",&target);

    int result = binarySearch(arr, 0, n - 1, target);
    if (result != -1)
        printf("Element %d found at index %d.\n", target, result);
    else
        printf("Element %d not found in the array.\n", target);
    return 0;
}
