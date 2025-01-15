#include "sort.h"
#include <iostream>
#include <vector>

void bubbleSort(int *arr, int size, bool asc) {
    if (asc == true) {
        for (int j = 0; j < size - 1; j++) {
            for (int i = j + 1; i < size; i++) {
                if (arr[j] > arr[i]) {
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }
    else {
        for (int j = 0; j < size - 1; j++) {
            for (int i = j + 1; i < size; i++) {
                if (arr[j] < arr[i]) {
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }
}

void selectionSort(int* arr, int size) {
    for (int i = 0; i < size; i++) { // i = 0
        int minIndex = i;  // minIndex = 0
        for (int j = i + 1; j < size; j++) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(int* arr, int size) {
    if (arr == nullptr || size <= 0) {
        return;
    }
    for (int i = 1; i < size; i++) {
        int buf = arr[i];
        for (int j = i - 1; j > -1; j--) {
            if (arr[j] <= buf) {
                arr[j + 1] = buf;
                break;
            }
            else {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void merge(int* arr, int left, int mid, int right);

void mergeSort(int* arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void merge(int* arr, int left, int mid, int right) {
    const int n1 = mid - left + 1;
    const int n2 = right - mid;
    int* L = new int[n1]; 
    int* R = new int[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] R, L;
}

int partition(int arr[], int low, int high);

void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}
