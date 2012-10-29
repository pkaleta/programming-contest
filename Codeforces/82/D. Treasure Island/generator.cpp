#include <cstdlib>
#include <iostream>

using namespace std;

char grid[20][20];

int main() {
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            grid[i][j] = '.';
        }
    }

    for (int i = 0; i < 20; ++i) {
        grid[0][i] = '#';
        grid[19][i] = '#';
        grid[i][0] = '#';
        grid[i][19] = '#';
    }

    srand(time(0));
    for (int i = 0; i < 50; ++i) {
        int x = rand() % 20;
        int y = rand() % 20;
        grid[y][x] = '#';
    }
    for (char c = 'A'; c <= 'Z'; ++c) {
        int x = (rand() % 18) + 1;
        int y = (rand() % 18) + 1;
        grid[y][x] = c;
    }

    cout << "20 20" << endl;
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    cout << 0 << endl;

    return 0;
}
