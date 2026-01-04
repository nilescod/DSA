#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> numbers;
ll minValueDP[21][21], maxValueDP[21][21];
bool dpComputed[21][21];

void computeMinMax(int start, int end) {
    if (start == end) {
        minValueDP[start][end] = numbers[start];
        maxValueDP[start][end] = numbers[start];
        return;
    }

    if (dpComputed[start][end]) return;

    dpComputed[start][end] = true;

    ll currentMin = LLONG_MAX;
    ll currentMax = LLONG_MIN;

    for (int split = start; split < end; split++) {
        computeMinMax(start, split);
        computeMinMax(split + 1, end);

        ll leftMin = minValueDP[start][split];
        ll leftMax = maxValueDP[start][split];
        ll rightMin = minValueDP[split + 1][end];
        ll rightMax = maxValueDP[split + 1][end];

        vector<ll> possibleValues = {
            leftMin + 2 * rightMin,
            leftMin + 2 * rightMax,
            leftMax + 2 * rightMin,
            leftMax + 2 * rightMax
        };

        for (ll val : possibleValues) {
            currentMin = min(currentMin, val);
            currentMax = max(currentMax, val);
        }
    }

    minValueDP[start][end] = currentMin;
    maxValueDP[start][end] = currentMax;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int n;
        cin >> n;

        numbers.resize(n);
        for (int i = 0; i < n; i++)
            cin >> numbers[i];

        memset(dpComputed, false, sizeof(dpComputed));

        computeMinMax(0, n - 1);

        cout << minValueDP[0][n - 1] << " " << maxValueDP[0][n - 1] << "\n";
    }

    return 0;
}
