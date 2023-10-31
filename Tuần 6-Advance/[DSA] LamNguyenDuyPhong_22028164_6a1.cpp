#include<bits/stdc++.h>

using namespace std;

class Graph {
    int n, m;
    vector<vector<int>> adjacent;
public:
    Graph(int n, int m) {
        this->n = n;
        this->m = m;
        for (int i = 0; i <= n; i++) {
            vector<int> tmp;
            adjacent.push_back(tmp);
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adjacent[u].push_back(v);
        }
    }

    void dfs(vector<bool> &traversaled, int index, vector<int> &s) {
        traversaled[index] = true;
        for (auto i : adjacent[index]) {
            if (!traversaled[i]) {
                dfs(traversaled, i, s);
            }
        }
        s.push_back(index);
    }

    void potologycalSort() {
        vector<bool> traversaled(n, false);
        stack<int> res;
        for (int i = 1; i <= n; i++) {
            if (!traversaled[i]) {
                vector<int> s;
                dfs(traversaled, i, s);
                for (auto i : s) {
                    res.push(i);
                }
            }
        }
        while (!res.empty()) {
            cout << res.top() << " ";
            res.pop();
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph graph(n, m);
    graph.potologycalSort();
}
