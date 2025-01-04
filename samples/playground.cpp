#include "cppUtils.h"
#include <chrono>

int main() {
    int arr[] = {10, 5, 6, 2, 3, 7, 8, 9, 1, 4};
    auto startTime = std::chrono::high_resolution_clock::now();
    quickSort(arr, 0, arr[0] - 1);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    std::cout << "Function execution time: " << duration.count() << " milliseconds" << std::endl;
    printArray(arr, 10);
}