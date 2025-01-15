#include "printers.h"
#include <iostream>

void printArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << ' ';
	}
}
