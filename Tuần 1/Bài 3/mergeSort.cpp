#include <iostream>
#include <vector>

using namespace std;

int len;

void mergeArr(vector<int>& arr, int left, int mid, int right) {
    vector<int> newArr;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if(arr[i] < arr[j]) {
            newArr.push_back(arr[i]);
            i++;
        } else {
            newArr.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid) {
        newArr.push_back(arr[i]);
        i++;
    }
    while (j <= right) {
        newArr.push_back(arr[j]);
        j++;
    }
    int len = right - left + 1;
    for (int k = 0; k < len; k++) {
        arr[left] = newArr[k];
        left++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        mergeArr(arr, left, mid, right);
        for (int i = 0; i < len; i++) cout << arr[i] << ' ';
        cout << endl;
    }
}

int main() {
    vector<int> arr;
    cin >> len;
    for (int i = 0; i < len; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    mergeSort(arr, 0, n);
}
