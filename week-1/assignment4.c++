#include <iostream>

struct Resource {
    int* data;

    Resource() : data(new int(42)) {
        std::cout << "Resource acquired at " << data << std::endl;
    }

    ~Resource() {
        std::cout << "Resource released at " << data << std::endl;
        delete data;
    }
};

int main() {
    Resource r;
    std::cout << *r.data << std::endl;

    return 0;
}