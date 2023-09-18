#include <iostream>
#include <queue>

using namespace std;

class Stack {
private:
    queue<int> q1, q2;
public:
    void push(int value) {
        q2.push(value);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    void pop() {
        q1.pop();
    }
};

int main() {
    int n;
    cin >> n;
    Stack s;
    for (int i = 0; i < n; i++) {
        int con;
        cin >> con;
        switch (con) {
            case 1:
                cin >> con;
                s.push(con);
                break;
            case 2:
                s.pop();
                break;
        }
    }
}

