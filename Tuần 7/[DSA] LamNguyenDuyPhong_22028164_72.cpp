#include<bits/stdc++.h>

using namespace std;

class DynamicProgramming{
    vector<vector<int>> table;
    vector<int> weight;
    vector<int> value;
    int items, capacity;
public:
    DynamicProgramming(int items, int capacity) {
        this->items = items;
        this->capacity = capacity;
        for (int i = 0; i <= items; i++) {
            vector<int> tmp(capacity + 1);
            table.push_back(tmp);
        }
        for (int i = 0; i <= capacity; i++) {
            table[0][i] = 0;
        }
        for (int i = 1; i <= items; i++) {
            table[i][0] = 0;
        }
        for (int i = 0; i <= items; i++) {
            if (i == 0) {
                weight.push_back(0);
                value.push_back(0);
            }
            else {
                int a, b;
                cin >> a >> b;
                weight.push_back(a);
                value.push_back(b);
            }
        }
    }

    void optimize() {
        for (int i = 1; i <= items; i++) {
            for (int j = 1; j <= capacity; j++) {
                if (j - weight[i] > 0 && weight[i] <= j){
                    table[i][j] = max(table[i - 1][j], table[i][j - weight[i]] + value[i]);
                } else if (weight[i] <= j) {
                    table[i][j] = max(table[i - 1][j], value[i]);
                } else {
                    table[i][j] = 0;
                }
            }
        }
        for (int i = 0; i <= items; i++) {
            for (int j = 0; j <= capacity; j++) {
                cout << table[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    DynamicProgramming dp(n, m);
    dp.optimize();
}
