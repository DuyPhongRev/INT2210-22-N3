#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if(arr[i] < arr[j]) {
                int tmp = arr[i];
                arr.erase(arr.begin() + i);
                arr.insert(arr.begin() + j, tmp);
            }
        }
    }
    for (auto i: arr) cout << i << " ";
}
