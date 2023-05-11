#include <iostream>
#include <vector>

using namespace std;

struct Item {
    int weight;
    int value;
};

int knapsack(vector<Item>& items, int capacity) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (items[i - 1].weight > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - items[i - 1].weight] + items[i - 1].value);
        }
    }

    return dp[n][capacity];
}

int main() {
    vector<Item> items = {{2, 12}, {1, 10}, {3, 20}, {2, 15}};
    int capacity = 5;

    int maxVal = knapsack(items, capacity);

    cout << "Maximum value: " << maxVal << endl;

    return 0;
}
