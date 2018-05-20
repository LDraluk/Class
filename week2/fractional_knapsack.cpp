#include <iostream>
#include <vector>

using std::vector;
struct item {
    int v;
    int w;
    item(int w, int v) : w(w) , v(v) {};
    
};

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;
    size_t size = values.size();
    std::vector<item> items;
    // items.resize(size);
    for (int i=0 ; i<size; i++) {
        items.push_back(item(weights[i], values[i]));
    }
    sort(items.begin(),
         items.end(),
         [](item const& lhs, item const& rhs){
             return lhs.v/lhs.w > rhs.v/rhs.w;
         }
         );
    int curr = 0;
    for (size_t i = 0; i<size; i++) {
        if (curr + items[i].w <= capacity) {
            value += items[i].v;
            curr= curr + items[i].w;
        } else {
            int remainder = capacity - curr;
            value = value +  items[i].v * ((double)remainder / items[i].w);
            break;
        }
    }
    return value;
}

int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> values[i] >> weights[i];
    }
    
    double optimal_value = get_optimal_value(capacity, weights, values);
    
    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}

