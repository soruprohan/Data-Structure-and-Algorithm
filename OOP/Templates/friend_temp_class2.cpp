#include <iostream>
using namespace std;

template <class T>
class Vector {
    T *v;
    int size;

public:
    Vector() {}
    Vector(int n) : size(n) {
        v = new T[size];
        for (int i = 0; i < size; i++) {
            v[i] = 0;
        }
    }
    Vector(int n, T elem) : size(n) {
        v = new T[size];
        for (int i = 0; i < size; i++) {
            v[i] = elem;
        }
    }
    Vector(int n, T *arr) : size(n) {
        v = new T[size];
        for (int i = 0; i < size; i++) {
            v[i] = arr[i];
        }
    }
    ~Vector() {
        delete[] v;
    }

    // Friend declaration for operator*
    friend Vector operator*(Vector &ob1, Vector &ob2);

    // Overloaded << operator
    friend ostream &operator<<(ostream &COUT, Vector &ob) {
        cout << ob.size << endl;
        for (int i = 0; i < ob.size; i++) {
            cout << ob.v[i] << " ";
        }
        return COUT;
    }
};

template <class T>
Vector operator*(Vector<T> &ob1, Vector<T> &ob2) {
    if (ob1.size != ob2.size) {
        cerr << "Vector sizes must match for multiplication." << endl;
        exit(1);
    }

    Vector<T> ob3(ob1.size);
    for (int i = 0; i < ob1.size; i++) {
        ob3.v[i] = ob1.v[i] * ob2.v[i];
    }

    return ob3;
}

int main() {
    Vector<int> vec1(3);
    Vector<int> vec2(3);
    Vector<int> vec3;

    cout << vec1 << endl;
    cout << vec2 << endl;
    vec3 = vec1 * vec2;

    cout << vec3;
    return 0;
}
