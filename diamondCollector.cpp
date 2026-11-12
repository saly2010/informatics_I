#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

     freopen("diamond.in", "r", stdin);
     freopen("diamond.out", "w", stdout);

    int N;
    long long K;
    if (!(cin >> N >> K)) return 0;

    vector<long long> diamonds(N);
    for (int i = 0; i < N; i++) {
        cin >> diamonds[i];
    }

    sort(diamonds.begin(), diamonds.end());

    vector<int> max_a_partir_de(N);
    int j = 0;
    for (int i = 0; i < N; i++) {
        while (j < N && diamonds[j] - diamonds[i] <= K) {
            j++;
        }
        max_a_partir_de[i] = j - i;
    }

    vector<int> max_a_droite(N + 1, 0);
    int current_max = 0;
    for (int i = N - 1; i >= 0; i--) {
        current_max = max(current_max, max_a_partir_de[i]);
        max_a_droite[i] = current_max;
    }

    int max_total_diamonds = 0;
    j = 0;
    for (int i = 0; i < N; i++) {
        while (j < N && diamonds[j] - diamonds[i] <= K) {
            j++;
        }

        int total_actuel = (j - i) + max_a_droite[j];
        max_total_diamonds = max(max_total_diamonds, total_actuel);
    }

    cout << max_total_diamonds << "\n";

    return 0;
}