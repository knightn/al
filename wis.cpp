#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start, end, weight;
};

bool intervalComp(const Interval& i1, const Interval& i2) {
    return i1.end < i2.end;
}

int findLatestNonConflicting(const vector<Interval>& intervals, int i) {
    for (int j = i - 1; j >= 0; j--) {
        if (intervals[j].end <= intervals[i].start)
            return j;
    }
    return -1;
}

int weightedIntervalScheduling(const vector<Interval>& intervals) {
    int n = intervals.size();
    vector<int> dp(n, 0);

    sort(intervals.begin(), intervals.end(), intervalComp);

    dp[0] = intervals[0].weight;

    for (int i = 1; i < n; i++) {
        int includedWeight = intervals[i].weight;
        int l = findLatestNonConflicting(intervals, i);
        if (l != -1)
            includedWeight += dp[l];

        dp[i] = max(includedWeight, dp[i - 1]);
    }

    return dp[n - 1];
}

int main() {
    vector<Interval> intervals = {
        {1, 4, 2},
        {3, 5, 1},
        {0, 6, 3},
        {5, 7, 4},
        {3, 8, 2},
        {5, 9, 3},
        {6, 10, 4},
        {8, 11, 2}
    };

    int maxWeight = weightedIntervalScheduling(intervals);

    cout << "Maximum weight achievable: " << maxWeight << endl;

    return 0;
}
