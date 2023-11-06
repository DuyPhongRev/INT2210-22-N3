#include <iostream>
#include <vector>

using namespace std;

bool isVisited(int a, vector<int> visited) {
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] == a) return true;
    }
    return false;
}

void traversal(int a, vector<vector<int>> network, vector<int> &visited){
    visited.push_back(a);
    for (int i = 0; i < network[a-1].size(); i++) {
        if(!isVisited(network[a-1][i], visited)) {
            traversal(network[a-1][i], network, visited);
        }
    }
}

int main() {
    int n, b;
    cin >> n >> b;
    vector<vector<int>> network;
    for (int i = 0; i < n; i++) {
        vector<int> newVec;
        network.push_back(newVec);
    }
    for (int i = 0; i < b; i++) {
        int x, y;
        cin >> x >> y;
        network[x-1].push_back(y);
        network[y-1].push_back(x);
    }
    vector<int> visited;
    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!isVisited(i, visited)) {
            components++;
            traversal(i, network, visited);
        }
    }
    cout << components;
}
