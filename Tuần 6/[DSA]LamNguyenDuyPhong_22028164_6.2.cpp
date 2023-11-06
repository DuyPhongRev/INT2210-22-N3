#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int shortestPath(int cur, int des, vector<vector<int>> network, int index) {
    if (cur == des) return index;
    int res = INT_MAX;
    for (int i = 0; i < network[cur].size(); i++) {
        res = min(res, shortestPath(network[cur][i], des, network, index + 1));
    }
    return res;
}

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;
    vector<vector<int>> network;
    for(int i = 0; i < n; i++) {
        vector<int> newVec;
        network.push_back(newVec);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        network[a].push_back(b);
    }
    cout << shortestPath(X, Y, network, 0);
}
