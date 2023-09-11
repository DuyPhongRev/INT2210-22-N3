#include <iostream>
#include <vector>
#define MAX 100
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(MAX, 0);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        cnt += v[tmp];
        v[tmp]++;
    }
    cout << cnt;
}
