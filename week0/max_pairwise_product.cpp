#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const vector<int>& numbers) {
    size_t n = numbers.size();
    if (n==1) {
        return numbers[0];
    }
    std::sort(numbers.begin(), numbers.end(),
              [](int const& lhs,int const& rhs){ return lhs < rhs;});
    
    return numbers[n-1] * numbers[n-2];
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    
    long long result = MaxPairwiseProduct(numbers);
    cout << result << "\n";
    return 0;
}
