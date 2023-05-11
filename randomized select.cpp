#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j <= right - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

int randomPartition(vector<int>& arr, int left, int right) {
    srand(time(NULL));
    int randomIndex = left + rand() % (right - left + 1);
    swap(arr[randomIndex], arr[right]);
    return partition(arr, left, right);
}

int randomizedSelect(vector<int>& arr, int left, int right, int k) {
    if (left == right) {
        return arr[left];
    }
    int pivotIndex = randomPartition(arr, left, right);
    int numSmaller = pivotIndex - left + 1;
    if (k == numSmaller) {
        return arr[pivotIndex];
    } else if (k < numSmaller) {
        return randomizedSelect(arr, left, pivotIndex - 1, k);
    } else {
        return randomizedSelect(arr, pivotIndex + 1, right, k - numSmaller);
    }
}

// Example usage:
int main() {
    vector<int> arr = {4, 7, 1, 9, 2, 5, 3, 6, 8};
    int k = 5;
    int kthSmallest = randomizedSelect(arr, 0, arr.size() - 1, k);
    cout << "The " << k << "th smallest element is: " << kthSmallest << endl;
    return 0;
}
