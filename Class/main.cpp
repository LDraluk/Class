#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <cfloat>

using std::vector;
using std::string;
using std::pair;
using std::min;
struct Point {
   int x,y;
   Point(){ x=0;y=0;}
   Point(int x ,int y) :x(x),y(y){};
};

//A utility function to find the distance between two points
double dist(Point p1, Point p2)
{
   return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
               (p1.y - p2.y)*(p1.y - p2.y)
               );
}

// A Brute Force method to return the smallest distance between two points
// in P[] of size n
double bruteForce(vector<Point> points,int l,int r)
{
   float min = DBL_MAX;
   for (int i = l; i <r-l; ++i)
      for (int j = i+1; j < r-l; ++j)
         if (dist(points[i], points[j]) < min)
            min = dist(points[i], points[j]);
   return min;
}
double closest(vector<Point> points,int l,int r) {
   if (r-l <=3) {
      return bruteForce(points,l,r);
   }
   // Find the middle point
   int mid = (r-l)/2;
   double dl = closest(points,l,mid);
   double dr = closest(points,mid,r-l);
   double d = min(dl,dr);
   vector<Point> strip(r-l);
   int j = 0;
   for (int i = 0; i < r-l; i++) {
      if (abs(points[i].x - points[mid].x) < d) {
         strip[j] = points[i];
         j++;
      }
   }
   std::sort(strip.begin(),strip.end(),[](Point const&  rhs,Point const&  lhs)
             { return lhs.y>rhs.y;});
   double min = d;
   for (int i = 0; i < j; ++i)
      for (int k = i+1; k < r-l && (strip[k].y - strip[i].y) < min; ++k)
         if (dist(strip[i],strip[k]) < min)
            min = dist(strip[i], strip[k]);
   
   if (d <min) return d;
   else return min;

}
double minimal_distance(vector<int> x, vector<int> y) {
   vector<Point> points;
   points.resize(x.size());
   for (int i=0; i<=(x.size()-1); i++) {
      points[i] = Point(x[i],y[i]);
   }
   std::sort(points.begin(),points.end(),[](Point const&  rhs,Point const&  lhs)
             { return lhs.x>rhs.x;});

   return closest(points,0,x.size());
}

int main() {
   size_t n;
   std::cin >> n;
   vector<int> x(n);
   vector<int> y(n);
   for (size_t i = 0; i < n; i++) {
      std::cin >> x[i] >> y[i];
   }
   std::cout << std::fixed;
   std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}
