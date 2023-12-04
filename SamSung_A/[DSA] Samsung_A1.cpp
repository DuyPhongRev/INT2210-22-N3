#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;

bool checkEulerCycle() {
    for (int i = 0; i < 9; i++) {
        if (adj[i].size() % 2 == 1) return false;
    }
    return true;
}

bool hasHamiltonianCycle(int start, vector<bool>& visited) {
  for (int i = 0; i < 9; i++) {
    if (!visited[i]) return false;
  }

  if (adj[start][start]) return true;

  for (int next : adj[start]) {
    if (!visited[next]) {
      visited[next] = true;
      if (hasHamiltonianCycle(next, visited)) {
        return true;
      }
      visited[next] = false;
    }
  }

  return false;
}

int main() {
    string s;
    for (int i = 0; i < 9; i++)
    {
        vector<int> tmp;
        adj.push_back(tmp);
    }
    while (cin >> s)
    {
        if (s == "0") break;
        adj[s[0]].push_back(s[2]);
        adj[s[2]].push_back(s[0]);
    }
    if (checkEulerCycle()) cout << "This graph has Euler cycle." << endl;
    else cout << "This graph does not have Euler cycle." << endl;

    bool connected = true;
  vector<bool> visited(9, false);
  visited[0] = true;
  for (int i = 0; i < 9; i++) {
    if (!visited[i]) {
      connected = false;
      break;
    }
  }

  if (!connected) {
    cout << "This graph does not have a Hamiltonian cycle." << endl;
    return 0;
  }

  visited[0] = true;
  if (hasHamiltonianCycle(0, visited)) {
    cout << "This graph has a Hamiltonian cycle." << endl;
  } else {
    cout << "This graph does not have a Hamiltonian cycle." << endl;
  }

  return 0;
}
