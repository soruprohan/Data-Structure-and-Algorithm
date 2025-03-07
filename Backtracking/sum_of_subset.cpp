#include <iostream>
#include <vector>

using namespace std;

int m; // target sum
vector<int> w; // array of weights
vector<int> x; // solution vector
int n; // number of elements

void SumOfSub(int s, int k, int r) {
    x[k] = 1; // include w[k] in the solution
    if (s + w[k] == m) {
        // Print solution if the target sum is reached
        for (int i = 0; i <= k; ++i) {
            if (x[i] == 1)
                cout << w[i] << " ";
        }
        cout << endl;
    } else if (s + w[k] + w[k + 1] <= m) {
        // Recursive call including w[k]
        SumOfSub(s + w[k], k + 1, r - w[k]);
    }

    if ((s + r - w[k] >= m) && (s + w[k + 1] <= m)) {
        x[k] = 0; // exclude w[k] from the solution
        // Recursive call excluding w[k]
        SumOfSub(s, k + 1, r - w[k]);
    }
}

int main() {
    cout << "Enter the number of elements: ";
    cin >> n;
    w.resize(n);
    x.resize(n, 0); // Initialize solution vector with 0
    int totalWeight = 0;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        totalWeight += w[i];
    }

    cout << "Enter the target sum: ";
    cin >> m;

    cout << "Subsets with sum " << m << " are:" << endl;
    SumOfSub(0, 0, totalWeight);

    return 0;
}

