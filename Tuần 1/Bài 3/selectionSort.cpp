#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++) {
            if(arr[m] >= arr[j]) m = j;
        }
        swap(arr[i], arr[m]);
    }
    for (auto i: arr) cout << i << " ";
}
