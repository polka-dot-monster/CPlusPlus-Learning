#include <iostream>
#include <string>

struct Person {
    std::string name;
    int age;
};

struct Buffer {
    int* data;
    size_t size;

    Buffer(size_t n) : size (n), data(new int[n]) { }

    ~Buffer() {
        delete[] data;
    }

    //copy constructor (deep copy)Used when Creating a new object (initialization)
    Buffer(const Buffer& other)
        : size(other.size), data(new int[other.size]) {
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
    }

    // copy assignment which will deep copy the contents and assign it (used when assigning to an existing operator)
    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            delete[] data;

            size = other.size;
            data = new int[size];
            for (size_t i=0; i<size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    //without a copy constructor, the deep copy will cause a double free

    // Move constructors avoids expensive deep copies during temporary transfers

    Buffer(Buffer&& other) noexcept {
        size = other.size;
        data = other.data;

        other.size = 0;
        other.data = nullptr;
    }

    //move assignment 
    Buffer& operator=(Buffer&& other) noexcept
    {
        if (this == &other) return *this;

        delete[] data;

        size = other.size;
        data = other.data;

        other.size = 0;
        other.data = nullptr;

        return *this;
    }
};

int main() {
    {
        Person a{"Alice", 30};
        Person b = a;
        Person c = std::move(a);
        //move operator will move the string buffer to the C's pointer location
        //primitives like int will be copied over.

        std::cout << "person a: name='" << a.name << "' age=" << a.age << std::endl;
        std::cout << "person b: name='" << b.name << "' age=" << b.age << std::endl;
        std::cout << "person c: name='" << c.name << "' age=" << c.age << std::endl;
    }

    Buffer b1(5);
    b1.data[0] = 7;

    Buffer b2 = b1;      // deep copy
    b2.data[0] = 100;

    std::cout << b1.data[0] << "\n";  // still 7
    std::cout << b2.data[0] << "\n";  // 100

    // the moment the destructor is defined, and the type owns a raw pointer or a resource
    // also must define copy ctor + copy assignment (deep copy), or
    // disable copying

    Buffer b4 = std::move(b1); // move ctor
    Buffer b5(5);
    b5 = std::move(b2); // move assignment
}