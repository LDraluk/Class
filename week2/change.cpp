#include <iostream>
#include <vector>

int get_change(int m) {
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

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

