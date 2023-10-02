#include <iostream>
#include <vector>
using namespace std;

// Một Node trong cây
class Node {
    // Chứa thông tin của Node đó
    int data;
    // Con trỏ đến Node cha
    Node* fatherNode;

    // Con trỏ đến các Node con
    // Đây là một danh sách liên kết (con trỏ đến con đầu tiên)
    // Thứ tự ưu tiên từ nhỏ đến lớn (con nhỏ được duyệt trước)
    vector<Node> child;

public:
    Node() {

    }

    Node(int tmp) {
        data = tmp;
    }

    Node(Node *father) {
        fatherNode = father;
    }

    int getData() {
        return data;
    }

    void setData(int data) {
        this->data = data;
    }

    vector<Node> getChild() {
        return child;
    }

    void push(Node newChild) {
        child.push_back(newChild);
    }

    friend class Tree;
};

// Lớp Cây
class Tree {
    // Chứa một Node gốc
    Node* root;
public:
    Tree(Node *tmp) {
        root = tmp;
    }

    Node* findNode(Node *father, int data) {
        if (father) {
            vector<Node> child = father->getChild();

            for(int i = 0; i < child.size(); i++) {
                if (child[i].getData() != data) findNode(&child[i], data);
                else return father;
            }
        }
        return null;
    }
    // Các hàm khởi tạo khác nếu cần thiết

    // Hàm thêm một Node vào cây
    // Hàm trả về false nếu Node cha không tồn tại trên cây
    // hoặc Node father đã có con là data
    bool insert(int father, int data) {
        Node *node = findNode(root, data);
        Node *newNode = new Node(node);
        node->push(*newNode);
    }

    // Hàm xoá một Node trên cây
    // Nếu không phải Node lá xoá Node đó và toàn bộ các Node con của nó
    // Hàm trả về số lượng Node đã xoá
    // Nếu Node data không tồn tại trả về 0 (zero)
    int remove(int data) {
        Node *node = findNode(root, data);
        if (!node) return 0;
        return countNode(node);
    }

    int countNode(Node *father) {
        int sum = 0;
        if (father) {
            vector<Node> child = father->getChild();
            for(int i = 0; i < child.size(); i++) {
                sum += countNode(&child[i]);
            }
        }
        return sum;
    }

    // Hàm in ra các Node theo thứ tự preorder
    void preorder(Node *father) {
        if (father) {
            vector<Node> child = father->getChild();
            cout << father->getData();
            for(int i = 0; i < child.size(); i++) {
                preorder(&child[i]);
            }
        }
    }

    // Hàm in ra các Node theo thứ tự postorder
    void postorder(Node *father) {
        if (father) {
            vector<Node> child = father->getChild();
            for(int i = 0; i < child.size(); i++) {
                preorder(&child[i]);
            }
            cout << father->getData();
        }
    }

    // Hàm kiểm tra cây nhị phân
    bool isBinaryTree(Node *father) {
        if (father) {
            vector<Node> child = father->getChild();
            if (child.size() == 0) return true;
            else if (child.size() == 1) return isBinaryTree(&child[0]);
            else if (child.size() == 2) return (isBinaryTree(&child[0]) && isBinaryTree(&child[1]));
            else return false;
        }
        return true;
    }

    // Hàm kiểm tra cây tìm kiếm nhị phân
    bool isBinarySearchTree() {
        if (father) {
            vector<Node> child = father->getChild();
            if (child.size() == 0) return 1;
            else if (child.size() == 1 && (child[0] <= father->getData() || child[1] >= father->getData())) return isBinarySearchTree(&child[0]);
            else if (child.size() == 2 && child[0] <= father->getData() && child[1] >= father->getData()) return (isBinarySearchTree(&child[0]) && isBinarySearchTree(&child[1]));
            else return 0;
        }
        return 1;
    }

    // Hàm kiểm tra cây max-heap
    bool isMaxHeapTree() {
        if (father) {
            vector<Node> child = father->getChild();
            if (child.size() == 0) return 1;
            else if (child.size() == 1 && child[0] <= father->getData()) return isBinarySearchTree(&child[0]);
            else if (child.size() == 2 && child[0] <= father->getData() && child[1] >= father->getData()) return (isBinarySearchTree(&child[0]) && isBinarySearchTree(&child[1]));
            else return 0;
        }
        return 1;
    }

    // Hàm in ra các Node theo thứ tự inorder nếu là cây nhị phân
    void inorder(Node *father) {
        if (father == root && !isBinaryTree(root)) {
            return;
        }
        if (father) {
            vector<Node> child = father->getChild();
            cout << child[0].getData();
            cout << father->getData();
            cout << child[1].getData();
        }
    }

    // Hàm trả về độ cao của cây
    int height(Node *father, int &height) {
        int max;
        if (father) {
            vector<Node> child = father->getChild();
            if(child.size() == 0) return 1;
            for(int i = 0; i < child.size(); i++) {
                max = max(max, calDepth(&child[i], height + 1));
            }
            return max;
        }
        return height;
    }

    // Hàm trả về độ sâu của một Node
    int depth(int data) {
        Node *node = findNode(root, data);
        if(!node) return 0;
        return calDepth(node, 0);
    }

    int calDepth(Node* father, int depth) {
        int max;
        if (father) {
            vector<Node> child = father->getChild();
            for(int i = 0; i < child.size(); i++) {
                max = max(max, calDepth(&child[i], depth + 1));
            }
            return max;
        }
        return depth;
    }

    // Hàm đếm số lượng lá
    int numOfLeaves(Node *father) {
        int sum = 0;
        if (father) {
            vector<Node> child = father->getChild();
            if(child.size() == 0) return 1;
            for(int i = 0; i < child.size(); i++) {
                sum += numOfLeaves(&child[i]);
            }
        }
        return sum;
    }

    int findMax(Node *father) {
        int num = 0;
        if (father) {
            vector<Node> child = father->getChild();
            num = max(num, father->getData());
            for(int i = 0; i < child.size(); i++) {
                findMaxChild(&child[i]);
            }
        }
        return num;
    }

    // Hàm trả về Node có nhiều con nhất
    int findMaxChild(Node *father) {
        int num = 0;
        if (father) {
            vector<Node> child = father->getChild();
            num = max(num, child.size());
            for(int i = 0; i < child.size(); i++) {
                findMaxChild(&child[i]);
            }
        }
        return num;
    }
};

int main(int argc, char const *argv[]) {
    Node *head = new Node(5);
    Tree *tree = new Tree(head);
    tree->preorder(head);
    return 0;
}
