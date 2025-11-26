#include<iostream>
#include<vector>

void by_value(std::vector<int> v) {
    std::cout << v.data() << std::endl;
}

void by_const_ref(const std::vector<int>& v) {
    std::cout << v.data() << std::endl;
}

void by_ref(std::vector<int>& v) {
    std::cout << v.data() << std::endl;
}

int main() {
    std::vector<int> nums = {1,2,3,4};
    by_value(nums);
    by_const_ref(nums);
    by_ref(nums);
}