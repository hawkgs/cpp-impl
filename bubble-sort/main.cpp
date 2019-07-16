#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = n; i >= 0; i--) {
        for (int j = 0; j < i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int swap = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = swap;
            }
        }
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
    bubbleSort(arr, 9);
    printArray(arr, 9);

    return 0;
}
