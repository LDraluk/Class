#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;
using std::queue;

class TreeOrders {
    int n;
    vector <int> key;
    vector <int> left;
    vector <int> right;
    
public:
    void read() {
        cin >> n;
        key.resize(n);
        left.resize(n);
        right.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> key[i] >> left[i] >> right[i];
        }
    }
    void recur_pre_order(int root,vector<int>& result) {
        result.push_back(key[root]);
        if (left[root] != -1) {
            recur_pre_order(left[root],result);
        }
        if (right[root] != -1) {
            recur_pre_order(right[root],result);
        }
        
    }
    void recur_post_order(int root,vector<int>& result) {
        if (left[root] != -1) {
            recur_post_order(left[root],result);
        }
        if (right[root] != -1) {
            recur_post_order(right[root],result);
        }
        result.push_back(key[root]);
        
    }
    void recur_in_order(int root,vector<int>& result) {
        if (left[root] != -1) {
            recur_in_order(left[root],result);
        }
        result.push_back(key[root]);
        if (right[root] != -1) {
            recur_in_order(right[root],result);
        }
        
    }
    vector<int> in_order() {
        vector<int> result;
        recur_in_order(0,result);
        
        return result;
    }
    
    vector<int> pre_order() {
        vector<int> result;
        recur_pre_order(0,result);
        
        return result;
    }
    
    vector <int> post_order() {
        vector<int> result;
        recur_post_order(0,result);
        return result;
    }
    vector<int> level_order() {
        vector<int> result;
        queue<int> q;
        int root = 0;
        q.push(root);
        while (!q.empty()) {
            result.push_back(key[root]);
            if (left[root] != -1) {
                q.push(left[root]);
            }
            if (right[root] != -1) {
                q.push(right[root]);
            }
            q.pop();
            root = q.front();
            
        }
        return result;
        
    }
    
};
