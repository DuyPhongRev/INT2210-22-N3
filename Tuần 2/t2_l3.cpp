#include <iostream>

using namespace std;

struct node {
    int value = 0;
    node* next = NULL;
    node () {}
    node (int _value, node* _next) {
        next = _next;
        value = _value;
    }
};

class linkList {
private:
    node* head = new node();
public:
    void insertNode (int p, int value) {
        node* tmp = head;
        if (p < 0) return;
        for (int i = 0; i < p; i++) {
            if(tmp->next) tmp = tmp->next;
        }
        node* hold = tmp->next;
        node* newNode = new node(value, hold);
        tmp->next = newNode;
    }
    void deleteNode (int p) {
        node* tmp = head;
        for (int i = 0; i < p; i++) {
            if(tmp->next) tmp = tmp->next;
        }
        if (tmp && tmp->next && tmp->next->next) {
            tmp = tmp->next->next;
        }
    }
    void printList () {
        node* tmp = head->next;
        while (tmp) {
            cout << tmp->value;
            tmp = tmp->next;
        }
    }
};

int main() {
    int n;
    cin >> n;
    linkList* ll = new linkList();
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "insert") {
            int p, v;
            cin >> p >> v;
            ll->insertNode(p, v);
        }
        else {
            int p;
            cin >> p;
            ll->deleteNode(p);
        }
    }
    ll->printList();
}
