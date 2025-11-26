#include<iostream>
#include <iostream>

#include <iostream>

struct TinyView {
    const char* begin;
    const char* end;

    size_t size() const {
        return end - begin;
    }

    void print() const {
        for (const char* p = begin; p != end; ++p) {
            std::cout << *p;
        }
        std::cout << std::endl;
    }


};

std::ostream& operator<<(std::ostream& os, const TinyView& view) {
    for (const char* p = view.begin; p != view.end; ++p) {
        os << *p;
    }
    return os;
}

int main() {
    const char* msg = "Hello C++ World";

    TinyView view{msg, msg+5};
    view.print();
    std::cout << "Size of view: " << view.size() << std::endl;

    std::cout << view << " this is printed using overloaded << operator." << std::endl;
    
    return 0;
}