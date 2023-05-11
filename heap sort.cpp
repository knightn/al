#include <iostream>
#include <vector>

using namespace std;

int heapSort(vector<int>& arr) {
    int comparisons = 0;  // initialize a variable to count comparisons
    
    // Build max heap
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        comparisons += heapify(arr, n, i);
    }
    
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        comparisons += heapify(arr, i, 0);
    }
    
    return comparisons;   // return the total number of comparisons made
}

int heapify(vector<int>& arr, int n, int i) {
    int comparisons = 0;
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        comparisons++;
        comparisons += heapify(arr, n, largest);
    }
    
    return comparisons;   // return the number of comparisons made in this heapify
}

// Example usage:
int main() {
    vector<int> arr = {5, 2, 4, 6, 1, 3};
    int comparisons = heapSort(arr);
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl << "Number of comparisons: " << comparisons << endl;
    return 0;
}
