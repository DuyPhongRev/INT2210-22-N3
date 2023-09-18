#include <iostream>
#include <stack>

using namespace std;

class Queue {
private:
    stack<int> s1, s2;
public:
    void enQueue(int value) {
        s2.push(value);
    }

    void deQueue() {
        if (s1.empty()) {
            if (s2.empty()) return;
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
        s1.pop();
    }
};

int main() {
    int n;
    cin >> n;
    Queue q;
    for (int i = 0; i < n; i++) {
        int con;
        cin >> con;
        switch (con) {
            case 1:
                cin >> con;
                q.enQueue(con);
                break;
            case 2:
                q.deQueue();
                break;
        }
    }
}
