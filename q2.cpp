#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        int minIndex = left;
        int maxIndex = right;

        // Find min and max in the unsorted part
        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        // Place minimum at left
        swap(arr[left], arr[minIndex]);

        // If max was at left, we corrected its position
        if (maxIndex == left)
            maxIndex = minIndex;

        // Place maximum at right
        swap(arr[right], arr[maxIndex]);

        left++;
        right--;
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2, 7, 1, 6};
    int n = 8;

    improvedSelectionSort(arr, n);

    cout << "Sorted Array: ";
    for (int x : arr) cout << x << " ";
}
