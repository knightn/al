#include <iostream>
#include <vector>

using namespace std;

int mergeSort(vector<int>& arr, int left, int right) {
    int comparisons = 0;   // initialize a variable to count comparisons
    
    if (left < right) {
        int mid = left + (right - left) / 2;
        comparisons += mergeSort(arr, left, mid);
        comparisons += mergeSort(arr, mid + 1, right);
        comparisons += merge(arr, left, mid, right);
    }
    
    return comparisons;   // return the total number of comparisons made
}

int merge(vector<int>& arr, int left, int mid, int right) {
    int comparisons = 0;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1);
    vector<int> R(n2);
    
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
        comparisons++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    return comparisons;   // return the number of comparisons made in this merge
}

// Example usage:
int main() {
    vector<int> arr = {5, 2, 4, 6, 1, 3};
    int comparisons = mergeSort(arr, 0, arr.size() - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl << "Number of comparisons: " << comparisons << endl;
    return 0;
}
