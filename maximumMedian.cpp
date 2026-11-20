#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long k;
    if (scanf("%d %lld", &n, &k) != 2) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }

    sort(a.begin(), a.end());

    int mid = n / 2;
    long long low = a[mid];
    long long high = a[mid] + k;
    long long ans = a[mid];

    while (low <= high) {
        long long target = low + (high - low) / 2;
        long long ops_needed = 0;

        for (int i = mid; i < n; ++i) {
            if (a[i] < target) {
                ops_needed += (target - a[i]);
                if (ops_needed > k) break;
            }
        }

        if (ops_needed <= k) {
            ans = target;
            low = target + 1;
        } else {
            high = target - 1;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
