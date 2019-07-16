#include <iostream>

using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = n; i > 0; i--) {
        int maxIdx = 0;

        for(int j = 0; j < i; j++) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }

        int swap = arr[i - 1];
        arr[i - 1] = arr[maxIdx];
        arr[maxIdx] = swap;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ',';
    }
    cout << endl;
}

int main() {
    int arr[] = { 3, 5, 7, 2, 4, 8, 6, 1, 44 };

    printArray(arr, 9);
    selectionSort(arr, 9);
    printArray(arr, 9);

    return 0;
}
