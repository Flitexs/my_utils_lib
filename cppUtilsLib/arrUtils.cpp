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