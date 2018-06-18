#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
    int x = a[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] <= x) {
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[j]);
    return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
    if (l >= r) {
        return;
    }
    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    int m = partition2(a, l, r);
    
    randomized_quick_sort(a, l, m - 1);
    randomized_quick_sort(a, m + 1, r);
}
template <typename T>
void merge(vector<T> &a, int l, int mid, int r) {
    int id1 = mid-l+1;
    int id2 = r-mid;
    vector<T> first(id1);
    vector<T> second(id2);
    //copy
    for (int i=0; i<id1; i++) {
        first[i] = a[l+i];
    }
    for (int i=0; i<id2; i++) {
        second[i] = a[mid + 1 + i];
    }
    //initial indices
    int idf = 0;
    int ids = 0;
    int ida = l;
    while(idf < id1 && ids < id2) {
        if (first[idf] <= second[ids]) {
            a[ida] = first[idf];
            idf++;
        } else {
            a[ida] = second[ids];
            ids++;
        }
        ida++;
    }
    //copy remainder
    for (int i=idf; i<id1; i++) {
        a[ida] = first[i];
        ida++;
    }
    for (int i=ids; i<id2; i++) {
        a[ida] = second[i];
        ida++;
    }
}
template<typename T>
void merge_sort(vector<T> &a, int l, int r) {
    if (l<r) {
        int mid = l +(r-l)/2;
        merge_sort(a, l, mid);
        merge_sort(a, mid+1, r);
        merge(a, l, mid, r);
    }
    
}
template<typename T>
void bubble_sort(vector<T> &a, int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (a[j] > a[j+1]) {
                swap(a[j],a[j+1]);
            }
        }
    }
}
template <typename T>
void select_sort(vector<T> &a, int n) {
    int min_idx = 0;
    for (int i=0; i<n-1;i++) {
        min_idx = i;
        for (int j=i+1; j< n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        swap(a[i],a[min_idx]);
    }
}
int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    //    randomized_quick_sort(a, 0, a.size() - 1);
    //   merge_sort(a, 0, a.size() - 1);
    bubble_sort(a, n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
}
