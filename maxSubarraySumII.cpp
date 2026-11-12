#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    if (!(cin >> n >> a >> b)) return 0;

    vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        long long x;
        cin >> x;
        pref[i] = pref[i - 1] + x;
    }

    deque<int> dq;
    long long max_sum = -4e18; 

    for (int i = a; i <= n; ++i) {
        int new_idx = i - a;
        while (!dq.empty() && pref[dq.back()] >= pref[new_idx]) {
            dq.pop_back();
        }
        dq.push_back(new_idx);

        while (!dq.empty() && dq.front() < i - b) {
            dq.pop_front();
        }

        max_sum = max(max_sum, pref[i] - pref[dq.front()]);
    }

    cout << max_sum << "\n";

    return 0;
}
