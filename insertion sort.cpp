#include <iostream>
#include <vector>

using namespace std;

int insertionSort(vector<int>& arr) {
    int comparisons = 0;   // initialize a variable to count comparisons
    
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j -= 1;
            comparisons++;   // increment comparison count
        }
        arr[j + 1] = key;
    }
    
    return comparisons;   // return the total number of comparisons made
}

// Example usage:
int main() {
    vector<int> arr = {5, 2, 4, 6, 1, 3};
    int comparisons = insertionSort(arr);
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl << "Number of comparisons: " << comparisons << endl;
    return 0;
}
