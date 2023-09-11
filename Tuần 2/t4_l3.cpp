#include <iostream>
#define MAX 100

using namespace std;

class Queue {
    int rear = -1;
    int arr[MAX];
public:
    void enqueue(int value) {
        if (rear > MAX - 1) {
            cout << "Overflow!";
        } else {
            rear++;
            arr[rear] = value;
        }
    }
    void dequeue() {
        for (int i = 0; i <  rear; i++) {
            arr[i] = arr[i+1];
        }
        rear--;
    }
    void print() {
        for (int i = 0; i <= rear; i++) cout << arr[i] << " ";
    }
};

int main() {
    int n;
    cin >> n;
    Queue* q = new Queue();
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "enqueue") {
            int value;
            cin >> value;
            q->enqueue(value);
        } else {
            q->dequeue();
        }
    }
    q->print();
}
