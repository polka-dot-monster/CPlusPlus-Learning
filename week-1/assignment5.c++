#include <iostream>
#include <vector>

int sum_ptr(const int* begin, const int* end) {
    int s = 0;
    for (const int* p = begin; p != end; ++p) {
        s += *p;
    }
    return s;
}


int sum_vec(const std::vector<int>& v) {
    int s = 0;
    for (size_t i = 0; i<v.size(); ++i) {
        s += v[i];
    }
    return s;
}

int main() {
    std::vector<int> v = {10,20,30,40};
    std::cout << sum_vec(v) << std::endl;;
    std::cout << sum_ptr(v.data(), v.data() + v.size()) << std::endl;
    return 0;
}