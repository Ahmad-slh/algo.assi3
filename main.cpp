#include <bits/stdc++.h>
#include <vector>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
using namespace std;

int partition(int arr[],int low,int high)
{
//choose the pivot

int pivot=arr[high];
//Index of smaller element and Indicate
//the right position of pivot found so far
int i=(low-1);

for(int j=low;j<=high;j++)
{
	//If current element is smaller than the pivot
	if(arr[j]<pivot)
	{
	//Increment index of smaller element
	i++;
	swap(arr[i],arr[j]);
	}
}
swap(arr[i+1],arr[high]);
return (i+1);
}

// The Quicksort function Implement

void quickSort(int arr[],int low,int high)
{
// when low is less than high
if(low<high)
{
	// pi is the partition return index of pivot

	int pi=partition(arr,low,high);

	//Recursion Call
	//smaller element than pivot goes left and
	//higher element goes right
	quickSort(arr,low,pi-1);
	quickSort(arr,pi+1,high);
}
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
void quickSort(int arr[], int low, int high);


void calculateExecutionTime(const vector<int>& data, void (*sortFunc)(int[], int, int)) {
    int n = data.size();
    vector<int> dataCopy = data;  // Make a copy of the data as sorting modifies the array
    int* array = dataCopy.data();

    // Start timer
    auto start = chrono::high_resolution_clock::now();

    // Perform sorting
    sortFunc(array, 0, n - 1);

    // Stop timer and calculate duration
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

    // Print the duration
    cout << "Time taken by function: " << duration.count() << " milliseconds" << endl;

}

int main() {
  vector<int> smallData = generateTestData("small");
    vector<int> mediumData = generateTestData("medium");
    vector<int> largeData = generateTestData("large");

    // Sorting small data
    int* arraySmall = smallData.data();
    int nSmall = smallData.size();
    quickSort(arraySmall, 0, nSmall - 1);

     calculateExecutionTime(smallData, quickSort);

    // Sorting medium data
    int* arrayMedium = mediumData.data();
    int nMedium = mediumData.size();
    quickSort(arrayMedium, 0, nMedium - 1);

    calculateExecutionTime(mediumData, quickSort);

    // Sorting large data
    int* arrayLarge = largeData.data();
    int nLarge = largeData.size();
    quickSort(arrayLarge, 0, nLarge - 1);



      calculateExecutionTime(largeData, quickSort);

    return 0 ;

    }
// This Code is Contributed By Diwakar Jha
