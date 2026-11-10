#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element {
    int value;
    int index;
};

bool compareElements(const Element& a, const Element& b) {
    return a.value < b.value;
}

int main() {

    int n;
    long long x;
    if (!(cin >> n >> x)) return 0;

    vector<Element> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].value;
        a[i].index = i + 1; 
    }

    sort(a.begin(), a.end(), compareElements);

    for (int i = 0; i < n - 2; ++i) {
        long long target = x - a[i].value;
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            long long current_sum = (long long)a[left].value + a[right].value;

            if (current_sum == target) {
                cout << a[i].index << " " << a[left].index << " " << a[right].index << "\n";
                return 0;
            } else if (current_sum < target) {
                left++; 
            } else {
                right--; 
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
