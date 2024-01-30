// Optimized implementation of Bubble sort
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
#include <chrono>

using namespace std;
using namespace std::chrono;

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++) {
		swapped = false;
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}

		// If no two elements were swapped
		// by inner loop, then break
		if (swapped == false)
			break;
	}
}

// Function to print an array
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << " " << arr[i];
}

// Function to generate test data of a specified size
vector<int> generateTestData(const string& size) {
    int n;
    if (size == "small") {
        n = 100;   // Small size
    } else if (size == "medium") {
        n = 1000;  // Medium size
    } else if (size == "large") {
        n = 10000; // Large size
    } else {
        throw invalid_argument("Invalid size. Choose 'small', 'medium', or 'large'.");
    }

    vector<int> data(n);
    srand(time(nullptr)); // Seed for random number generation

    for (int i = 0; i < n; ++i) {
        data[i] = rand() % 10000; // Random numbers between 0 and 9999
    }

    return data;
}

// Function to measure execution time
void measureExecutionTime(const string& size) {
    vector<int> data = generateTestData(size);

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    // Place your code here that uses the generated data

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(t2 - t1).count();

    cout << "Time taken to generate " << size << " data: " << duration << " milliseconds" << endl;
}



// Driver program to test above functions
int main()
{
	   // Measure execution time for generating small data
    measureExecutionTime("small");

    // Measure execution time for generating medium data
    measureExecutionTime("medium");

    // Measure execution time for generating large data
    measureExecutionTime("large");

    return 0;
}
// This code is contributed by shivanisinghss2110
