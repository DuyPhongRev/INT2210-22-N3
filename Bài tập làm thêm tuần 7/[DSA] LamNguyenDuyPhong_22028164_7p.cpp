#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, m;
    vector<char> sm;
    vector<char> sn;
    cin >> n >> m;
    sm.push_back('-');
    sn.push_back('-');
    for (int i = 0; i < n; i++) {
        char tmp;
        cin >> tmp;
        sn.push_back(tmp);
    }
    for (int i = 0; i < m; i++) {
        char tmp;
        cin >> tmp;
        sm.push_back(tmp);
    }
    int dp[m + 1][n + 1];
    for (int i = 0; i <= n; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (sm[i] == sn[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[m][n];
}
