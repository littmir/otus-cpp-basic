#include <cstring>
#include <iostream>
#include <string>

namespace motivation {
    class String {
        //  Say: syntax, this
    public:
        String() = default;
        String(const char* cString) {

            if (cString != nullptr) {
                const size_t lengthWithNullTerminator = std::strlen(cString) + 1;
                data = new char[lengthWithNullTerminator];
                std::copy(cString, cString + lengthWithNullTerminator, data);
            }
        }
        std::string toStdString() const { return data ? data : ""; }

    private:
        char* data = nullptr;
    };

    void example() {
        String hello("Hello");

        String world("world");
        std::cout << hello.toStdString() << " " << world.toStdString() << std::endl;
    }
} // namespace motivation

namespace first_attempt {
    struct String {
        String() = default;
        String(const char* cString) {

            if (cString) {
                const size_t lengthWithNullTerminator = std::strlen(cString) + 1;
                data = new char[lengthWithNullTerminator];
                std::copy(cString, cString + lengthWithNullTerminator, data);
            }
        }
        ~String() {
            // Say: typical error
            delete[] data;
        }
        std::string toStdString() const { return data ? data : ""; }
        char* data = nullptr;
    };

    void example() {
        // Say: constructor
        String a = "Hello";
        /*String b = a; //oops
        std::cout << a.toStdString() << " " << b.toStdString() << std::endl;*/
    }
} // namespace first_attempt

namespace second_attempt {
    struct String {
        String() = default;
        String(const char* cString) { initFrom(cString); }
        ~String() { delete[] data; }
        String(const String& other) { initFrom(other.data); }
        std::string toStdString() const { return data ? data : ""; }
        void initFrom(const char* cString);
        char* data = nullptr;
    };

    void String::initFrom(const char* cString) {
        if (cString) {
            const size_t lengthWithNullTerminator = std::strlen(cString) + 1;
            data = new char[lengthWithNullTerminator];
            std::copy(cString, cString + lengthWithNullTerminator, data);
        }
    }

    void example() {
        String a = "Hello";
        String b = a;
        std::cout << a.toStdString() << " " << b.toStdString() << std::endl;

        String world = "world";
        // b = world; // oops
        std::cout << a.toStdString() << " " << b.toStdString() << std::endl;
    }
} // namespace second_attempt

namespace solution {
    struct String {
        String() = default;
        String(const char* cString) { initFrom(cString); }
        ~String() { delete[] data; }
        String(const String& other) { initFrom(other.data); }
        String& operator=(const String& other) {
            if (this == &other) {
                return *this; // Gracefully handle self assignment
            }
            delete[] data;
            initFrom(other.data);
            return *this;
        }
        std::string toStdString() const { return data ? data : ""; }
        void initFrom(const char* cString);
        char* data = nullptr;
    };

    void String::initFrom(const char* cString) {
        if (cString) {
            const size_t lengthWithNullTerminator = std::strlen(cString) + 1;
            data = new char[lengthWithNullTerminator];
            std::copy(cString, cString + lengthWithNullTerminator, data);
        }
    }

    void example() {
        String a = "Hello";
        String b;
        b = a;
        std::cout << a.toStdString() << " " << b.toStdString() << std::endl;
    }
} // namespace solution

int main() {
    motivation::example();
    first_attempt::example();
    second_attempt::example();
    solution::example();
}
