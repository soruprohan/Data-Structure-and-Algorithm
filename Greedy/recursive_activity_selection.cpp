#include <iostream>
#include <vector>

using namespace std;

// Recursive Activity Selector
void recursiveActivitySelector(vector<int>& start, vector<int>& finish, int k, int n, vector<int>& result) {
    int m = k + 1;

    // Find the next activity whose start time is >= finish time of the current activity
    while (m <= n && start[m] < finish[k]) {
        m++;
    }

    if (m <= n) {
        // Add the activity to the result
        result.push_back(m);
        
        // Recursively call for the next valid activity
        recursiveActivitySelector(start, finish, m, n, result);
    }
}

int main() {
    // Example input: start and finish times of activities
    vector<int> start = {0, 1, 3, 0, 5, 8, 5};  // Start times (dummy element at index 0 for easier indexing)
    vector<int> finish = {0, 2, 4, 6, 7, 9, 9}; // Finish times (dummy element at index 0 for easier indexing)
    int n = start.size() - 1;                  // Number of activities (excluding the dummy element)

    // Add the first activity (1st index as a dummy element exists)
    vector<int> result = {1};

    // Call the recursive function starting from the first activity
    recursiveActivitySelector(start, finish, 1, n, result);

    // Print the selected activities
    cout << "Selected activities: ";
    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}
