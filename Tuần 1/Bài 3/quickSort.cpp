#include <iostream>
#include <algorithm>

using namespace std;

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[right], arr[++i]);
    pivot = i;
    for(int i = 0; i < 9; i++) cout << arr[i] << ' ';
    cout << endl;
    return pivot;
}

void quicksort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = partition(arr, left, right);
        quicksort(arr, left, pivot - 1);
        quicksort(arr, pivot + 1, right);
    }
}

int main() {
    int n;
    cin >> n;
    int arr;
    for (int i = 0; i < n; i++) cin >> arr[i];
    quicksort(arr, 0, 8);

}
