#include <iostream>

int gcd_naive(int a, int b) {
    int current_gcd = 1;
    for (int d = 2; d <= a && d <= b; d++) {
        if (a % d == 0 && b % d == 0) {
            if (d > current_gcd) {
                current_gcd = d;
            }
        }
    }
    return current_gcd;
}
long long gcd_fast(long long a, long long b) {
    if (b==0) return a;
    return gcd_fast(b,a%b);
}
long long lcm_fast(long long a, long long b) {
    long long gcd = gcd_fast(b,a);
    return static_cast<long long>(((static_cast<long long>(a*b))/(gcd)));
}
int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << gcd_fast(a, b) << std::endl;
    return 0;
}
