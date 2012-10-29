#include <fstream>
using namespace std;
const unsigned int MAX_SUM = 1024;
int n;
unsigned long long int dyn[MAX_SUM];
ifstream fin ("subset.in");
ofstream fout ("subset.out");

int main() {
    fin >> n;
    fin.close();
    int s = n*(n+1);
    if (s % 4) {
        fout << 0 << endl;
        fout.close ();
        return 0;
    }
    s /= 4;
    int i, j;
    dyn [0] = 1;
    for (i = 1; i <= n; i++)
        for (j = s; j >= i; j--) 
            dyn[j] += dyn[j-i];
    fout << (dyn[s]/2) << endl;
    fout.close();
    return 0;
}
