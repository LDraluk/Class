#include <iostream>
#include <vector>
using std::vector;
int get_change_naive(int m) {
    std::vector<int> change;
    change.resize(3);
    change[0] = 10;
    change[1] = 5;
    change[2] = 1;
    int n =0;
    int whole = 0;
    int remainder = 0;
    for (int i = 0; i<3; i++) {
        whole = m / change[i];
        remainder = m % change[i];
        n += whole;
        m = remainder;
        if ( m==0) break;
    }
    return n+m;
}
int get_change_fast(int V){
    std::vector<int> change;
    change.resize(3);
    change[2] = 10;
    change[1] = 5;
    change[0] = 1;
    vector<int> ans;
    
    // Traverse through all denomination
    for (int i=2; i>=0; i--)
    {
        // Find denominations
        while (V >= change[i])
        {
            V -= change[i];
            ans.push_back(change[i]);
        }
    }
    return (ans.size());
}
int main() {
    int m;
    std::cin >> m;
    std::cout << get_change_fast(m) << '\n';
}

