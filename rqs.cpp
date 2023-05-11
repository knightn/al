#include <iostream>
#include <vector>
#include <random>

using namespace std;

int quickSort(vector<int>& arr, int start, int end) {
    int comparisons = 0;
    if (start < end) {
        int p = randomizedPartition(arr, start, end, comparisons);
        comparisons += quickSort(arr, start, p - 1);
        comparisons += quickSort(arr, p + 1, end);
    }
    return comparisons;
}

int randomizedPartition(vector<int>& arr, int start, int end, int& comparisons) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(start, end);
    int randomIndex = dis(gen);
    swap(arr[randomIndex], arr[end]);
    return partition(arr, start, end, comparisons);
}

int partition(vector<int>& arr, int start, int end, int& comparisons) {
    int pivot = arr[end];
    int i = start - 1;
    for (int j = start; j <= end - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
            comparisons++;
        }
    }
    swap(arr[i + 1], arr[end]);
    comparisons++;
    return i + 1;
}

// Example usage:
int main() {
    vector<int> arr = {5, 2, 4, 6, 1, 3};
    int comparisons = quickSort(arr, 0, arr.size() - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl << "Number of comparisons: " << comparisons << endl;
    return 0;
}
