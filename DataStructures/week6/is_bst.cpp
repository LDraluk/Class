
#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
    int key;
    int left;
    int right;
    
    Node() : key(0), left(-1), right(-1) {}
    Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool IsBST(const vector<Node>& tree,int root, int left, int right) {
    if (tree.size() ==0) {
        return true;
    }
    if ( root == -1) {
        return true;
    }
    if (left != -1 && tree[left].key >tree[root].key) {
        return false;
    }
    if (right != -1 && tree[right].key < tree[root].key) {
        return false;
    }
    
    return IsBST(tree,tree[root].left, left, root)  && IsBST(tree,tree[root].right,root,right);
    
}

bool IsBinarySearchTree(const vector<Node>& tree) {
    return IsBST(tree,0,-1,-1);
}

int main() {
    int nodes;
    cin >> nodes;
    vector<Node> tree;
    for (int i = 0; i < nodes; ++i) {
        int key, left, right;
        cin >> key >> left >> right;
        tree.push_back(Node(key, left, right));
    }
    if (IsBinarySearchTree(tree)) {
        cout << "CORRECT" << endl;
    } else {
        cout << "INCORRECT" << endl;
    }
    return 0;
}
