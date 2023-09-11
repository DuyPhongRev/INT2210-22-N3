#include <iostream>

using namespace std;

struct node {
    int value = 0;
    node* next = NULL;
    node* prev = NULL;
    node () {}
    node(int _value, node* _prev, node* _next) {
        next = _next;
        prev = _prev;
        value = _value;
    }
};

class linkList {
private:
    node* head = new node();
public:
    void insertLast(int value) {
        node* tmp = head;
        while (tmp->next) {
            tmp = tmp->next;
        }
        node* newNode = new node(value, tmp, NULL);
        tmp->next = newNode;
    }
    int countTriplets() {
        int cnt = 0;
        if (head->next && head->next->next && head->next->next->next) {
            node *tmp = head->next->next;
            do {
                if (tmp->prev->value + tmp->next->value + tmp->value == 0) cnt++;
                tmp = tmp->next;
            } while(tmp->next);
        }
        return cnt;
    }
};

int main() {
    int n;
    cin >> n;
    linkList* ll = new linkList();
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        ll->insertLast(value);
    }
    cout << ll->countTriplets();
}
