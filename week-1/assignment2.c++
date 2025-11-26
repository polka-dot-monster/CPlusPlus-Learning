#include <iostream>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int* p = arr; // Pointer to the first element of the array

    bool isEqual = p == &arr[0];
    std::cout << "Pointer p points to the same location as &arr[0]: " << (isEqual ? "true" : "false") << std::endl;

    std::cout << "Address stored in pointer p: " << p << std::endl;
    std::cout << "value at the pointer p: " << *p << std::endl;
    std::cout << "value at pointer p + 1 ;: " << *(p + 1) << std::endl;
    std::cout << "pointer p + 1 address: " << (p + 1) << std::endl;

    std::cout << "how much bytes advance for p + 1: " << sizeof(int) << " bytes" << std::endl;

    p++;
    std::cout << "After incrementing, pointer p address: " << p << std::endl;
    std::cout << "After incrementing, value at pointer p: " << *p << std::endl;

    std::cout << &arr[0] << std::endl;
    std::cout << &arr[1] << std::endl;
    std::cout << &arr[2] << std::endl;
    //in this case, you should see that address increases by 4 bytes (int size) each time.
    
    return 0;
}