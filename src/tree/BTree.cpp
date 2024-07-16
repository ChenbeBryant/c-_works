#include <iostream>
#include <vector>
#include <iomanip>

struct BTree {
    int val;
    BTree *lChild, *rChild, *parent;
    BTree(int x) : val(x), lChild(nullptr), rChild(nullptr), parent(nullptr) {}
};

void printTreeUtil(BTree* root, int space, int height) {
    if (root == nullptr) {
        return;
    }

    space += height;

    printTreeUtil(root->rChild, space, height);

    std::cout << std::endl;
    for (int i = height; i < space; i++) {
        std::cout << " ";
    }
    std::cout << root->val << "\n";

    if (root->lChild) {
        for (int i = height; i < space - 2; i++) {
            std::cout << " ";
        }
        std::cout << "/";
    }
    if (root->rChild) {
        std::cout << " ";
        for (int i = height + 1; i < space; i++) {
            std::cout << " ";
        }
        std::cout << "\\";
    }

    std::cout << std::endl;
    printTreeUtil(root->lChild, space, height);
}

void printTree(BTree* root) {
    printTreeUtil(root, 0, 5);
}

int main() {
    BTree* root = new BTree(1);
    root->lChild = new BTree(2);
    root->rChild = new BTree(3);
    root->lChild->lChild = new BTree(4);
    root->lChild->rChild = new BTree(5);
    root->rChild->lChild = new BTree(6);
    root->rChild->rChild = new BTree(7);

    printTree(root);

    return 0;
}
