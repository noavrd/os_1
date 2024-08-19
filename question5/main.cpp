#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// פונקציה ליצירת מערך אקראי
void generateRandomArray(std::vector<int>& arr, int n) {
    for (int i = 0; i < n; i++) {
        arr.push_back((rand() % 100) - 25);
    }
}

// אלגוריתם נאיבי O(n^3)
int maxSubArraySumNaive(const std::vector<int>& arr) {
    int n = arr.size();
    int maxSum = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int currentSum = 0;
            for (int k = i; k <= j; k++) {
                currentSum += arr[k];
            }
            maxSum = std::max(maxSum, currentSum);
        }
    }
    return maxSum;
}

// אלגוריתם משופר O(n^2)
int maxSubArraySumImproved(const std::vector<int>& arr) {
    int n = arr.size();
    int maxSum = -1;
    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        for (int j = i; j < n; j++) {
            currentSum += arr[j];
            maxSum = std::max(maxSum, currentSum);
        }
    }
    return maxSum;
}

// אלגוריתם קָדָנֶה O(n)
int maxSubArraySumKadane(const std::vector<int>& arr) {
    int maxSum = arr[0];
    int currentSum = arr[0];
    for (size_t i = 1; i < arr.size(); i++) {
        currentSum = std::max(arr[i], currentSum + arr[i]);
        maxSum = std::max(maxSum, currentSum);
    }
    return maxSum;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " <seed> <size>" << std::endl;
        return 1;
    }

    int seed = std::atoi(argv[1]);
    int size = std::atoi(argv[2]);

    std::srand(seed);

    std::vector<int> arr;
    arr.reserve(size);
    generateRandomArray(arr, size);

    int maxSum;

    #ifdef VERSION_NAIVE
        maxSum = maxSubArraySumNaive(arr);
    #elif defined(VERSION_IMPROVED)
        maxSum = maxSubArraySumImproved(arr);
    #elif defined(VERSION_KADANE)
        maxSum = maxSubArraySumKadane(arr);
    #else
        std::cout << "No valid algorithm version defined." << std::endl;
        return 1;
    #endif

    std::cout << "Max Subarray Sum: " << maxSum << std::endl;

    return 0;
}