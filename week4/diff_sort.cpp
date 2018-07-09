#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using std::vector;
using std::swap;
// randomized quick sort
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
//selection sort
template <typename T>
void select_sort(vector<T> &a, int n) {
    int min_idx = 0;
    for (int i=0;i<n-1;i++) {
        min_idx = i;
        for ( int j = i+1; j<n-i-1; j++) {
            if (a[j]>a[min_idx]) {
                min_idx = j;
            }
        }
        swap(a[i],a[min_idx]);
    }
    
}
// bubble sort
template <typename T>
void bubble_sort(vector<T>& a,int n){
    for (int i=0; i < n-1; i++) {
        for (int j =0; j<n-i-1; j++) {
            if (a[j] > a[j+1]) {
                swap(a[j],a[j+1]);
            }
        }
    }
}
//merge sort
template <typename T>
void merge(vector<T> &a, int l, int mid, int r) {
    int id1 = mid-l+1;
    int id2 = r-mid;
    vector<T> first(id1);
    vector<T> second(id2);
    // copy
    for (int i =0; i<id1; i++) {
        first[i] = a[l+i];
    }
    for (int i =0 ; i<id2; i++) {
        second[i] = a[i+mid+1];
    }
    int idl =0;
    int idr =0;
    int idm =l;
    while (idl<id1 && idr<id2) {
        if (first[idl] <= second[idr]) {
            a[idm] = first[idl];
            idl++;
        }else{
            a[idm] = second[idr];
            idr++;
        }
        idm++;
    }
    for (int i = idl; i<id1; i++){
        a[idm] =first[i];
        idm++;
    }
    for (int i = idr; i<id2; i++){
        a[idm] =second[i];
        idm++;
    }
}
template<typename T>
void merge_sort(vector<T> &a, int l, int r) {
    if (l < r ) {
        int mid = l+(r-l)/2;
        merge_sort(a,l,mid);
        merge_sort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}
//quick sort
template <typename T>
int partition(vector<T>& a,int l,int r){
    T x = a[r];
    int i = l-1;
    for (int j = l; j<r-1;j++) {
        if (a[j]<=x) {
            i++;
            swap(a[j],a[i]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}
template <typename T>
void quick_sort(vector<T>& a,int l,int r){
    if (l>=r)
        return;
    int m = partition(a,l,r);
    quick_sort(a,l,m-1);
    quick_sort(a,m+1,r);
}
//insertion_sort
template <typename T>
void insertion_sort(vector<T>& a,int n) {
    if (n<=1) return;
    insertion_sort(a,n-1);
    T last = a[n-1];
    int i = n-2;
    while (i>=0 && a[i]>last) {
        a[i+1] = a[i];
        i--;
    }
    a[i+1] = last;
    
}
//heap sort
template <typename T>
void hepify(vector<T>& a,int n,int i) {
    int root = i;
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
    if (l<n && a[l] > a[root]) {
        root = l;
    }
    if (r<n && a[r] > a[root]) {
        root = r;
    }
    if ( root != i ) {
        swap(a[i],a[root]);
        hepify(a,n,root);
    }
    
}
template <typename T>
void heap_sort(vector<T>& a,int n) {
    
    for (int i = n/2-1; i>=0; i--)  {
        hepify(a,n,i);
    }
    for (int i = n-1; i>=0; i--) {
        swap(a[0],a[i]);
        hepify(a,i,0);
    }
}
//counting sort range from 0-1
void counting_sort(vector<int>& a,int n) {
    vector<int> counts = {0,0,0,0,0,0,0,0,0,0};
    for (int i =0; i<n;i++) {
        if (a[i]< counts.size()) {
            counts[a[i]]++;
        }else{
            counts.resize(a[i],0);
            counts[a[i]]++;
        }
    }
    // now refill counts array
    for (int i=1;i<counts.size();i++) {
        counts[i] += counts[i-1];
    }
    vector<int> out(n);
    for (int i=0; i < n ; i++) {
        out[counts[a[i]]-1] = a[i];
        counts[a[i]]--;
    }
    for (int i =0; i<n;i++) {
        a[i] = out[i];
    }
}

//radix sort
void radix_counting_sort(vector<int>& a,int n,int exp) {
    vector<int> counts = {0,0,0,0,0,0,0,0,0,0};
    for (int i =0; i<n;i++) {
        counts[(a[i]/exp)%10]++;
    }
    // now refill counts array
    for (int i=1;i<counts.size();i++) {
        counts[i] += counts[i-1];
    }
    vector<int> out(n);
    for (int i=n-1; i > 0 ; i--) {
        out[counts[(a[i]/exp)%10]-1] = a[i];
        counts[(a[i]/exp)%10]--;
    }
    for (int i =0; i<n;i++) {
        a[i] = out[i];
    }
}
void radix_sort(vector<int>& a,int n) {
    // figure out number of digit
    int mx = a[0];
    for (int i=1; i< n;i++) {
        if (a[i] > mx) {
            mx = a[i];
        }
    }
    for (int exp =1;mx/exp>0;exp *=10) {
        radix_counting_sort(a,n,exp);
    }
}
//bucket sort
void bucket_sort(vector<float>& a,int n) {
    vector<vector<float>> bucket(n);
    for (int i=0;i<n;i++) {
        int bi = n*a[i];
        bucket[bi].push_back(a[i]);
    }
    for (int i=0;i<n;i++) {
        std::sort(bucket[i].begin(),bucket[i].end());
    }
    int index = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<bucket[i].size(); j++) {
            a[index++] = bucket[i][j];
        }
    }
    
}
int main() {
    int n;
    std::cin >> n;
    vector<float> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    //    randomized_quick_sort(a, 0, a.size() - 1);
    //    quick_sort(a, 0, a.size() - 1);
    //  bubble_sort(a, n);
    bucket_sort(a,n);
    // insertion_sort(a, a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
}

