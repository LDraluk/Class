#include <iostream>
#include <vector>

using std::vector;
using ll = long long;
template <typename T>
ll merge(vector<T> &a,vector<T> &temp, size_t l, size_t mid, size_t r) {
    ll count = 0;
    //initial indices
    size_t idl = l;
    size_t idr = mid;
    size_t ida = l;
    while((idl <= mid-1) && (idr <=r)) {
        if (a[idl] <= a[idr]) {
            temp[ida] = a[idl];
            idl++;
        } else {
            temp[ida] = a[idr];
            idr++;
            count = count + (mid-idl);
        }
        ida++;
    }
    //copy remainder
    while (idl<=mid-1) {
        temp[ida++] = a[idl++];
    }
    while (idr<=r) {
        temp[ida++] = a[idr++];
    }
    for (size_t i = l; i<=r; i++) {
        a[i]=temp[i];
    }
    return count;
}

ll get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
    ll number_of_inversions = 0;
    size_t ave = 0;
    if (right>left) {
        ave = left + (right - left) / 2;
        number_of_inversions += get_number_of_inversions(a, b, left, ave);
        number_of_inversions += get_number_of_inversions(a, b, ave+1, right);
        number_of_inversions += merge(a, b, left, ave+1, right);
    }
    return number_of_inversions;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    vector<int> b(a.size());
    std::cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';
    //   for (size_t i = 0; i < a.size(); ++i) {
    //      std::cout << a[i] << ' ';
    //   }
}


