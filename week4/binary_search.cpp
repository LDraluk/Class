#include <iostream>
#include <cassert>
#include <vector>

using std::vector;
int binary_search(const vector<int> &a, int l,int r, int x) {
    if (x>a[r]) {
        return -1;
    }
    if (x<a[l]) {
        return -1;
    }
    int mid = l + (r-l)/2;
    if (a[mid] == x)
        return mid;
    if ( x < a[mid] )
        return binary_search(a,l,mid-1,x);
    return binary_search(a,mid+1,r,x);
    
}


int linear_search(const vector<int> &a, int x) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == x) return i;
    }
    return -1;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        //replace with the call to binary_search when implemented
        std::cout << binary_search(a, 0 , n-1, b[i]) << ' ';
    }
}

