
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;

template<typename T>
struct Node {
    T key;
    int left;
    int right;
    
    Node() : key(0), left(-1), right(-1) {}
    Node(T key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};
template <typename T>
bool IsBST(const vector<Node<T>>& tree,int root, int left, int right) {
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
template <typename T>
bool IsBinarySearchTree(const vector<Node<T>>& tree) {
    return IsBST(tree,0,-1,-1);
}

int main() {
    int nodes;
    cin >> nodes;
    vector<Node<int>> tree;
    for (int i = 0; i < nodes; ++i) {
        int key, left, right;
        cin >> key >> left >> right;
        tree.push_back(Node<int>(key, left, right));
    }
    if (IsBinarySearchTree(tree)) {
        cout << "CORRECT" << endl;
    } else {
        cout << "INCORRECT" << endl;
    }
    return 0;
}
