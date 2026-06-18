#include <iostream>

using namespace std;

// Returns the surviving position (1-based index)
int josephus(int n, int k) {
    // Base case: if there is only 1 person, they are the survivor
    if (n == 1)
        return 1;
    int cnt=(josephus(n - 1, k) + k - 1) % n + 1;
    cout<<cnt<<" ";
    // Recursive call and adjustment for shift
    return cnt;
}

int main() {
    int n = 7; // Number of people
    int k = 2; // Every kth person is eliminated

    cout << "The survivor is at position: " << josephus(n, k) << endl;
    return 0;
}
