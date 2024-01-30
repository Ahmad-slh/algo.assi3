#include <bits/stdc++.h>
#include <vector>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
// C++ program for Merge Sort
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid,
		int const right)
{
	int const subArrayOne = mid - left + 1;
	int const subArrayTwo = right - mid;

	// Create temp arrays
	auto *leftArray = new int[subArrayOne],
		*rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
	int indexOfMergedArray = left;

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne
		&& indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne]
			<= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray]
				= leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray]
				= rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray]
			= leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray]
			= rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
}


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

void mergeSort(int array[], int const begin, int const end);
void printArray(int A[], int size);



void measureExecutionTime(int arr[], int size, const string& dataSize) {
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    // Call the sorting algorithm (e.g., mergeSort)
    mergeSort(arr, 0, size - 1);

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(t2 - t1).count();

    cout << "Time taken to sort " << dataSize << " data: " << duration << " milliseconds" << endl;
}


// Driver code
int main()
{
     vector<int> smallData = generateTestData("small");
    vector<int> mediumData = generateTestData("medium");
    vector<int> largeData = generateTestData("large");

   // Sorting and Measuring Execution Time for Small Data
    int nSmall = smallData.size();
    int* arraySmall = smallData.data();
    cout << "Sorting small data...\n";
    measureExecutionTime(arraySmall, nSmall, "small");

    // Sorting and Measuring Execution Time for Medium Data
    int nMedium = mediumData.size();
    int* arrayMedium = mediumData.data();
    cout << "Sorting medium data...\n";
    measureExecutionTime(arrayMedium, nMedium, "medium");

    // Sorting and Measuring Execution Time for Large Data
    int nLarge = largeData.size();
    int* arrayLarge = largeData.data();
    cout << "Sorting large data...\n";
    measureExecutionTime(arrayLarge, nLarge, "large");

}

// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes
