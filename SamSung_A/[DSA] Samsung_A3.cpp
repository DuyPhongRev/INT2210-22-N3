#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_map<int, int> edges;
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        if (edges.find(u) != edges.end()) {
            if (edges[u] = v) {
                cnt++;
            }
        } else if (edges.find(u) == edges.end()) {
            edges[u] = v;
        }
    }
    cout << cnt;
}
