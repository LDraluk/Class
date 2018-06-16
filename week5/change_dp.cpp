#include <iostream>
#include  <vector>

using std::vector;

int get_change_slow(int m) {
    vector<int> coins{4,3,1};
    if (m==0) {
        return 0;
    }
    int max = 9999;
    int res = 9999;
    for (int i =0; i<3; i++) {
        if (coins[i] <= m) {
            int tmp_res = get_change_slow(m-coins[i]);
            if ((tmp_res != max) && res > tmp_res +1) {
                res = tmp_res+1;
            }
        }
    }
    return res;
}
int get_change(int m) {
    vector<int> coins{4,3,1};
    if (m==0) {
        return 0;
    }
    vector<int> table;
    table.resize(m+1);
    table[0] = 0;
    for (int i = 1; i<=m; i++) {
        table[i] = 9999;
        for (int j=0; j<3; j++) {
            if (coins[j]<=i) {
                int tmp_res = table[i-coins[j]];
                if ((tmp_res != 9999) && (table[i] > tmp_res +1)) {
                    table[i] = tmp_res+1;
                }
            }
        }
    }
    
    return table[m];
}
int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}


