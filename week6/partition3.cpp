#include <iostream>
#include <vector>

using std::vector;

int partition3(vector<int> &A) {
    int k = 3;
    size_t s = A.size();
    if (
    if (s<k){
        return 0;
    }
    // calculate sum and see if its divisible by 3
    int sum = 0;
    for (int i =0; i<s; i++) {
        sum += A[i];
    }
    if (sum % 3 != 0){
        return 0;
    }
    int sumsubset = sum/k;
    
 
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
