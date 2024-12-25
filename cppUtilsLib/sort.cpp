#include "sort.h"
#include <iostream>

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
        for (int j = i + 1; j < 6; j++) {
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
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] <= buf) {
                arr[j + 1] = buf;
                break;
            }
            else {
                arr[j + 1] = arr[j];
            }
        }
    }
}