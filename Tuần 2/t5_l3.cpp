#include <iostream>
#define MAX 100

using namespace std;

class Stack {
    int arr[MAX];
    int top = -1;
public:
    void push(int value) {
        if (top < MAX - 1) {
            top++;
            arr[top] = value;
        }
        else {
            cout << "Stack overflow!";
        }
    }
    void pop() {
        if(top >= 0) top--;
        else cout << "Stack is blank.";
    }
    void print() {
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
    }
};

int main() {
    int n;
    cin >> n;
    Stack* s = new Stack();
    for (int i = 0; i < n; i++) {
        string opt;
        cin >> opt;
        if (opt == "push") {
            int value;
            cin >> value;
            s->push(value);
        }
        else {
            s->pop();
        }
    }
    s->print();
}
