#include "arrUtils.h"
#include <random>

int* newRandomArr(int size) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

	int* arr = new int [size];
	for (int i = 0; i < size; i++) {
		arr[i] = dist(gen);
	}
	return arr;
}

int binarySearch(int* arr, int size, int x) {
	int high = size - 1;
	int low = 0;
	int mid = 0;
	while (low <= high) {
		mid = low + (high - low) / 2;
		if (x == arr[mid]) {
			return mid;
		}
		else if (x > arr[mid]) {
			low = mid+1;
		}
		else {
			high = mid-1;
		}
	}
	return -1;
}

int linearSearch(int* arr, int size, int number) {
	for (int i = 0; i <= size; i++) {
		if (arr[i] == number) {
			return i;
		}
	}
	return -1;
}

int* createMass(int size) {
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}
	return arr;
}
