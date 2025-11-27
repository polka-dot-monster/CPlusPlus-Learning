#include <iostream>

// Heap Vs Stack memory
// when "new" is used, data lives on the heap and needs to be manually deleted in the destructor.
// most of the time, stack memory is preferred as it is automatically managed.

struct Resource {
    int* data;

    Resource() : data(new int(42)) {
        std::cout << "Resource acquired at " << data << std::endl;
    }

    ~Resource() {
        std::cout << "Resource released at " << data << std::endl;
        delete data;
    }
    // Destructors should always be there if you have allocated memory in constructor
};

int main() {
    {
        Resource r;
        std::cout << *r.data << std::endl;
    }
    std::cout << "out of scope" << std::endl;

    return 0;
}