#include <iostream>

// Define a user-defined structure
struct MyStruct {
    int id;
    double value;
};

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    // Dynamically allocate memory for an array of MyStruct
    MyStruct* dynamicArray = new MyStruct[size];

    // Now you can use dynamicArray just like a regular array
    for (int i = 0; i < size; i++) {
        dynamicArray[i].id = i;
        dynamicArray[i].value = i * 2.5;
    }

    // Don't forget to delete the allocated memory when you're done
    delete[] dynamicArray;

    return 0;
}

