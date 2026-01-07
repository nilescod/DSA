//WE ARE GIVEN BLOOMING DAY ARRAY AND WE NEED TO FIND THE MINIMUM DAYS NEEDED TO MAKE M BOUQUETS OF K CONSECUTIVE FLOWERS
#include <bits/stdc++.h>
using namespace std;
//OPTIMAL SOLUTION GIVES TC OF O(n*log(max-min+1))

// Check if it's possible to make 'm' bouquets with 'k' adjacent flowers by day 'mid'
bool ifposs(vector<int>& a, int m, int k, int mid) {
    int cnt = 0, bouquets = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] <= mid) {
            cnt++;
            if (cnt == k) {
                bouquets++;
                cnt = 0;
            }
        } else {
            cnt = 0; // reset because flowers must be adjacent
        }
    }
    return bouquets >= m;
}

// Main function to find minimum day
int mindays(vector<int>& a, int m, int k) {
    int n = a.size();
    if (m * k > n) return -1;

    int low = *min_element(a.begin(), a.end());
    int high = *max_element(a.begin(), a.end());

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (ifposs(a, m, k, mid)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

int main() {
    int n;
    cout << "Enter number of flowers: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter blooming days of flowers: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    int m, k;
    cout << "Enter the value of m (bouquets) and k (flowers per bouquet): ";
    cin >> m >> k;

    int result = mindays(a, m, k);
    cout << "Minimum day to make " << m << " bouquets: " << result << endl;

    return 0;
}
