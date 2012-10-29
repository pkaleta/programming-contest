#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>		//UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>		//do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;

const int T = 20;
#define MR 10000

ofstream in("test.in"), out("test.out");

int t[MR], pom[MR];

int checksum(int N)
{
	int result = 1;
    REP(i,N)
        result = (31 * result + t[i]) % 1000003;
    return result;
}//checksum

void merge(int beg, int end)
{
	int half = (end-beg)/2;
	int wsk1 = beg, wsk2 = beg+half, wsk = beg;
	while(wsk1 < beg+half && wsk2 < end)
		if(t[wsk1] < t[wsk2])	//z drugiej czesci jest wieksza liczba		
		{
			in << "1";
			pom[wsk++] = t[wsk1++];
		}
		else		
		{
			in << "2";
			pom[wsk++] = t[wsk2++];	
		}
	while(wsk1 < beg+half) pom[wsk++] = t[wsk1++];
	while(wsk2 < end) pom[wsk++] = t[wsk2++];
	FOR(i,beg,end) t[i] = pom[i];
}//merge
void sort(int beg, int end)
{
	if(end-beg < 2)
		return;
	int half = (end-beg)/2;
	sort(beg,beg+half); sort(beg+half,end);
	merge(beg, end);
}//go

int main()
{
  srand ( time(NULL) );
	in << T << "\n";
	REP(i,T)
	{
		int N = rand()%(MR-1)+2;
		in << N << "\n";
		REP(j,N) t[j] = j+1;
		random_shuffle(t,t+N);
		out << "Case #" << i+1 << ": " << checksum(N) << "\n";
		sort(0,N);
		in << "\n";
	}
	return 0;
}
