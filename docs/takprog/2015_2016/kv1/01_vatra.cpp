#include <iostream>

using namespace std;

int main() {
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;
    cout << max(0, x1) + max(0, x2) + max(0, x3) << endl;
    return 0;
}
