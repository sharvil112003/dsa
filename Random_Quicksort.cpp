#include <bits/stdc++.h>
using namespace std;

int getRandomPivot(int s, int e) {
    srand(time(NULL));
    return s + rand() % (e - s + 1);
}

int partition(int* arr, int s, int e) {
    // Choose a random pivot index within the subarray [s, e]
    int pivotIdx = getRandomPivot(s, e);
    int pivot = arr[pivotIdx];

    // Swap the pivot element with the first element of the subarray
    swap(arr[pivotIdx], arr[s]);

    // Partitioning process
    int i = s + 1, j = e;
    while (i <= j) {
        while (i <= e && arr[i] <= pivot) {
            i++;
        }
        while (j > s && arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            // Swap elements at indices i and j
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    // Swap the pivot element to its correct position
    swap(arr[s], arr[j]);

    // Return the index of the pivot element
    return j;
}

void quicksort(int* arr, int s, int e) {
    if (s >= e) {
        return;
    }

    // Perform partitioning and get the index of the pivot
    int p = partition(arr, s, e);

    // Recursively apply quicksort on the two subarrays
    quicksort(arr, s, p - 1);
    quicksort(arr, p + 1, e);
}

int main() {
    int arr[5] = {13, 235, 54, 32, 37};
    int n = 5;

    // Call the quicksort function on the array
    quicksort(arr, 0, n - 1);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
