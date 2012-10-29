#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int x[10];
    memset(x, 0x0001, sizeof(x));

    for (int i = 0; i < 10; ++i) {
        cout << x[i] << endl;
    }
}
