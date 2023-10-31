#include <bits/stdc++.h>

using namespace std;

class Greedy {
    vector<vector<int>> items;
    int V;
    int n;

public:
    Greedy(int n, int V) {
        this->n = n;
        this->V = V;
        for (int i = 0; i < n; i ++) {
            int w, v, r;
            cin >> w >> v;
            r = v/w;
            items.push_back({r, w, v});
        }
    }

    void Optimize() {
        sort(items.begin(), items.end());
        int capacity = V;
        int res = 0;
        for (int i = n - 1; i >= 0; i--) {
            int weight = items[i][1];
            int value = items[i][2];
            if (capacity -  weight >= 0) {
                res += value*(capacity/weight);
                capacity -= weight*(capacity/weight);
            }
        }
        cout << res;
    }
};

int main() {
    int n, V;
    cin >> n >> V;
    Greedy greedy(n, V);
    greedy.Optimize();
}
