#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  return -1;
}
int majority_recurs(const vector<int>& el, int l, int r ) {
    if (l==r) return -1;
    if (l+1 == r) {
        return el[l];
    }
    int mid = l + (r-1)/2;
    int resl = majority_recurs(el, l, mid-1);
    int resr = majority_recurs(el, mid+1,r);
    if (resl == resr) {
        return resl;
    }
    if ((resl == -1)&&(resr != -1)) {
        return resr;
    }
    if ((resr == -1)&&(resl != -1)) {
        return resl;
    }
    if ((resr == -1)&&(resl == -1)) {
        return -1;
    }
    return -1;
}
int majority(const vector<int>& el, int n) {
    size_t size = el.size();
    std::unordered_map<int,int> counts;
    for (int i=0; i<size;i++) {
        auto it = counts.find(el[i]);
        if (it == counts.end()) {
            counts.insert({el[i],1});
        } else {
            it->second++;
        }
    }
    for (auto in_map : counts) {
        if (in_map.second > size/2) {
            return 1;
        }
    }
    return 0;
}
int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    //    std::cout << majority(a, n) << ' ';
    int res = (majority_recurs(a,0,n) == -1 ? 0: 1);
    std::cout << res << ' ';
    
}

