#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <string.h>
#include <vector>
#pragma comment(linker,"/STACK:256000000")

using namespace std;

long long secret;

int getRandomNumber() {
  secret = (secret * 5402147LL + 54321LL) % 10000001LL;
  return secret % 1000LL;
}

int a[200];

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	cin>>t;
	for (int tt=1; tt<=t; tt++){
		int n;
		int ans=-1;
		scanf("%d",&n);
		for (int i=0; i<n; i++)
			scanf("%d",&a[i]);
		vector <int> rs;
		int fnd=-1;
		for (long long i=0; i<10000001LL; i++){
			if (ans==2) break;
			secret=i;
			int gd=1;
			for (int j=0; j<n; j++){
				int v=getRandomNumber();
				if (v!=a[j]){
					gd=0;
					break;
				}
			}
			if (gd){
				secret=i;
				for (int j=0; j<n; j++)
					getRandomNumber();
				vector <int> cur;
				for (int j=0; j<10; j++)
					cur.push_back(getRandomNumber());
				if (fnd==-1){
					rs=cur;
					ans=1;
					fnd=1;
				}else
				{
					if (rs!=cur){
						ans=2;
					}
				}
			}
		}
		if (ans==1){
			for (int i=0; i<9; i++)
				printf("%d ",rs[i]);
			printf("%d\n",rs[9]);
		} else
			if (ans==2){
				printf("Not enough observations\n");
			} else
				printf("Wrong machine\n");
	}

	return 0;
}