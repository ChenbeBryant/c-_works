#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std::chrono;

// AVL Tree
#include "AVLTree.h"

// Red-Black Tree
#include "RBTree.h"

void testAVLTree(vector<int>& data) {
    AVLNode* root = nullptr;
    auto start = high_resolution_clock::now();
    for (int key : data) {
        root = insert(root, key);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "AVL Tree Insertion Time: " << duration.count() << " microseconds" << endl;

    start = high_resolution_clock::now();
    for (int key : data) {
        search(root, key);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "AVL Tree Search Time: " << duration.count() << " microseconds" << endl;

    random_shuffle(data.begin(), data.end());
    start = high_resolution_clock::now();
    for (int key : data) {
        root = deleteNode(root, key);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "AVL Tree Deletion Time: " << duration.count() << " microseconds" << endl;
}

void testRBTree(vector<int>& data) {
    RBTree tree;
    auto start = high_resolution_clock::now();
    for (int key : data) {
        tree.insert(key);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "RB Tree Insertion Time: " << duration.count() << " microseconds" << endl;

    start = high_resolution_clock::now();
    for (int key : data) {
        tree.search(key);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "RB Tree Search Time: " << duration.count() << " microseconds" << endl;

    random_shuffle(data.begin(), data.end());
    start = high_resolution_clock::now();
    for (int key : data) {
        tree.deleteNode(key);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "RB Tree Deletion Time: " << duration.count() << " microseconds" << endl;
}

int main() {
    vector<int> data;
    for (int i = 1; i <= 100000; ++i) {
        data.push_back(i);
    }

    cout << "Testing AVL Tree..." << endl;
    testAVLTree(data);

    cout << "Testing Red-Black Tree..." << endl;
    testRBTree(data);

    return 0;
}
