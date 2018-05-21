#include <iostream>
#include <cassert>
#include <vector>
typedef long long ll;

using  namespace std;

ll fibonacci_fast(int n) {
    if (n<=1) {
        return n;
    }
    std::vector<ll> fib;
    fib.reserve(n);
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i<n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n-1];
    
}
int fibonacci_huge_last_digit(int n) {
    std::vector<int> fib;
    fib.resize(60);
    fib[0] = 1;
    fib[1] = 1;
    for (int i =2; i<60; i++) {
        fib[i] = (fib[i-1] + fib[i-2])%10;
    }
    return fib[n%60];
}
template <typename T>
T fibonacci_sum_last_digit(T n) {
    n = (n+2)%60;
    T fib[n+1];
    fib[0]=0;
    fib[1]=1;
    for(T i = 2; i<=n;i++){
        fib[i] = (fib[i-1]%10 + fib[i-2]%10)%10;
    }
    if(fib[n] == 0){
        return 9;
    }
    return (fib[n]%10-1);
}
long long get_pisano_period(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
    return m*m;
}
long long get_fibonacci_huge(long long n, long long m) {
    long long remainder = n % get_pisano_period(m);
    
    long long first = 0;
    long long second = 1;
    
    long long res = remainder;
    
    for (int i = 1; i < remainder; i++) {
        res = (first + second) % m;
        first = second;
        second = res;
    }
    
    return res % m;
}

int main() {
    int n = 0;
    std::cin >> n;
    
    //    std::cout << fibonacci_fast(n) << '\n';
    std::cout << fibonacci_sum_last_digit(n) << '\n';
    //   std::cout << fibonacci_huge_last_digit(n) << '\n';
    //  long long n, m;
    // try n=281621358815590 m=30524  output should be 11963
    //std::cin >> n >> m;
    //std::cout <<  get_fibonacci_huge(n,m) << '\n';
    return 0;
}
