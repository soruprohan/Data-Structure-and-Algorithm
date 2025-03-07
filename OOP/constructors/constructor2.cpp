#include <iostream>

class MyClass {
public:
    int intValue;
    double doubleValue;
    char charValue;
    bool boolValue;

    MyClass() {} // Default constructor
};

int main() {
    MyClass obj;
    std::cout << "int: " << obj.intValue << std::endl;           // 0
    std::cout << "double: " << obj.doubleValue << std::endl;     // 0.0
    std::cout << "char: " << obj.charValue << std::endl;         // '\0'
    std::cout << "bool: " << obj.boolValue << std::endl;         // 0 (false)

    return 0;
}
