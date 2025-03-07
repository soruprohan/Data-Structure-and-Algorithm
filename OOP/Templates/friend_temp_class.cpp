#include<iostream>
using namespace std;

template <typename T>
class MyClass {
private:
    T data;
public:
    MyClass(T value) : data(value) {}

    // Declare the friend function
    template <typename U>
    friend void friendFunction(const MyClass<U>& obj);
};

// Define the friend function
template <typename U>
void friendFunction(const MyClass<U>& obj) {
    cout << "Friend function accessing private data: " << obj.data << endl;
}

int main() {
    MyClass<int> obj(42);
    friendFunction(obj); // Call the friend function
    return 0;
}
