#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v(5);

    vector<int>::iterator it,it1,it2,it3;

    for (it = v.begin(); it != v.end(); it++) {
        cin >> *it;
    }

    it = v.begin();
    auto ptr = next(it, 3);
    it1 = prev(ptr, 2);

    cout << *it << endl;
    cout << *ptr << endl;
    cout << *it1 << endl;

    for (auto it2 = v.rbegin(); it2 != v.rend(); ++it2) {
        cout << *it2 << " ";
    }

    cout << endl;
    cout<<v.max_size()<<endl;

    for (auto it2 = v.cbegin(); it2 != v.cend(); ++it2) {
        cout << *it2 << " ";
    }
}
