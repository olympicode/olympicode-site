#include <iostream>

using namespace std;

int main() {
    int b, c;
    cin >> b >> c;
    if(b + c >= 256) {
        cout << 0 << endl;
    } else {
        cout << 256 - max(b, c) << endl;
    }
    return 0;
}
