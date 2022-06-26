#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using std::vector;
int main() {
    vector<int> a(1);
    vector<int> b(2);
    vector<int> c(3);
    vector<int> d(4);

    vector<vector<int>> container;
    container.push_back(b);
    container.push_back(d);
    container.push_back(a);
    container.push_back(c);

    std::function<size_t(const vector<int>&)> sz_func = &vector<int>::size;
    vector<int> size_vec(4);

    std::transform(container.begin(), container.end(), size_vec.begin(), sz_func);

    for (auto itr = size_vec.begin(); itr != size_vec.end(); itr++) {

        std::cout << "size of vec: " << *itr << std::endl;
    }
}
