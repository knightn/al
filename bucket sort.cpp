#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketSort(vector<double>& arr) {
    int n = arr.size();
    vector<vector<double>> buckets(n);
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }
}

// Example usage:
int main() {
    vector<double> arr = {0.89, 0.42, 0.12, 0.53, 0.91, 0.27, 0.38, 0.52, 0.74, 0.89, 0.79};
    bucketSort(arr);
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
