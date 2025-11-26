#include<iostream>
#include<vector>

void by_value(std::vector<int> v) {
    std::cout << v.data() << std::endl;
    //this will copy the vector into a new memory location
}

void by_const_ref(const std::vector<int>& v) {
    std::cout << v.data() << std::endl;
    //this will not create a copy and cannot modify the original vector
}

void by_ref(std::vector<int>& v) {
    std::cout << v.data() << std::endl;
    //this will create a reference to the original vector and can modify the values
}

int main() {
    std::vector<int> nums = {1,2,3,4};
    by_value(nums);
    by_const_ref(nums);
    by_ref(nums);
}