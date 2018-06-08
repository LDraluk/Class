#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;
void partition3(vector<int> &a, int l, int r,int& m1, int& m2) {
   m1=l-1;
   m2=r;
   int cnt_m1 = l-1;
   int cnt_m2 = r;
   int v = a[r];
   while (true) {
      while (a[++m1] < v) {
      }
      while (a[--m2]>v) {
         if (m2 == l)
            break;
      }
      if (m1 >= m2) break;
      swap(a[m1],a[m2]);
      // Move all same left occurrence of pivot to beginning of
      // array and keep count using p
      if (a[m1] == v)
      {
         cnt_m1++;
         swap(a[cnt_m1], a[m1]);
      }
      
      // Move all same right occurrence of pivot to end of array
      // and keep count using q
      if (a[m2] == v)
      {
         cnt_m2--;
         swap(a[m2], a[cnt_m2]);
      }
   }
   
   // Move pivot element to its correct index
   swap(a[m1], a[r]);
   
   // Move all left same occurrences from beginning
   // to adjacent to arr[i]
   m2 = m1-1;
   for (int k = l; k < cnt_m1; k++, m2--)
      swap(a[k], a[m2]);
   
   // Move all right same occurrences from end
   // to adjacent to arr[i]
   m1 = m1+1;
   for (int k = r-1; k > cnt_m2; k--, m1++)
      swap(a[m1], a[k]);
}
void quick3_sort(vector<int> &a, int l, int r) {
   if (l >= r) {
      return;
   }
 //  int k = l + rand() % (r - l + 1);
  // swap(a[l], a[k]);
   int m1,m2;
   partition3(a, l, r, m1, m2);
   
   quick3_sort(a, l, m2);
   quick3_sort(a, m1, r);
}
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
int partition2_my(vector<int>&a, int l, int r) {
   int x = a[l];
   int big = l;
   for (int i=l+1;i<=r; i++) {
      if (a[i] <=x) {
         big++;
         swap(a[i],a[big]);
      }
   }
   swap(a[l],a[big]);
   return big;
   
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

int main() {
   int n;
   std::cin >> n;
   vector<int> a(n);
   for (size_t i = 0; i < a.size(); ++i) {
      std::cin >> a[i];
   }
   
   //   randomized_quick_sort(a, 0, a.size() - 1);
   quick3_sort(a, 0 , a.size()-1);
   for (size_t i = 0; i < a.size(); ++i) {
      std::cout << a[i] << ' ';
   }
}

