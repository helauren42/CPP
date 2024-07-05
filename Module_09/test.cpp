#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Utility function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    cout << endl;
}

// Utility function to merge two sorted ranges
void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);

	cout << "LEFT: ";
	printArray(left);
	cout << "RIGHT: ";
	printArray(right);
    int i = 0, j = 0, k = l;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < left.size()) {
        arr[k++] = left[i++];
    }

    while (j < right.size()) {
        arr[k++] = right[j++];
    }
    cout << "Post merge: ";
	printArray(arr);
}

// Function to insert an element into a sorted range
void insertionSort(vector<int>& arr, int l, int r) {
    for (int i = l + 1; i <= r; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= l && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Recursive implementation of the Ford-Johnson algorithm
void fordJohnsonSort(vector<int>& arr, int l, int r) {
    if (r - l <= 1)
	{
		cout << "\nleft: " << l << ", right: " << r <<  endl;
	    if (arr[l] > arr[r]) {
            swap(arr[l], arr[r]);
			printArray(arr);
        }
        return;
    }

    int mid = l + (r - l) / 2;

	cout << "\nleft: " << l << ", right: " << r <<  ", mid:" << mid << endl;
    // Recursively sort the left and right halves
	cout << "SORT LEFT: " << endl;
    fordJohnsonSort(arr, l, mid);
	
	cout << "SORT RIGHT: " << endl;
    fordJohnsonSort(arr, mid + 1, r);
	printArray(arr);

    // Merge the two sorted halves
	cout << "MERGE: " << endl;
	printArray(arr);
	merge(arr, l, mid, r);

    // Perform insertion sort to finalize the sorting
	cout << "INSERTION: " << endl;
	insertionSort(arr, l, r);
}

// Wrapper function for the Ford-Johnson algorithm
void sortFordJohnson(vector<int>& arr) {
    if (arr.size() < 2) return;
    fordJohnsonSort(arr, 0, arr.size() - 1);
}

int main() {
	// std::vector<int> arr = {66, 39, 40, 61, 57, 13, 85, 1, 2, 37, 48, 33, 63, 30, 100, 99, 80, 93, 25, 36, 11, 56, 28, 86, 44, 41, 97, 60, 43, 83, 20, 45, 87, 19, 18, 10, 3, 6, 69, 82, 42, 88, 14, 75, 29, 64, 16, 72, 59, 94, 21, 89, 67, 78, 27, 62, 34, 4, 23, 58, 24, 71, 8, 7, 92, 53, 55, 98, 22, 96, 15, 65, 50, 12, 79, 84, 68, 76, 17, 32, 38, 5, 95, 9, 77, 51, 49, 73, 26, 85, 54, 91, 47, 52, 70, 81, 74, 90, 35, 46};


	std::vector<int> arr = {66, 39, 40, 61, 57, 13, 85, 1, 2, 37, 48, 33, 63, 30, 100, 99, 80};

	std::cout << "Original array: ";
	for (int x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	sortFordJohnson(arr);

	std::cout << "\n\nSorted array: ";
	for (int x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	return 0;
}
