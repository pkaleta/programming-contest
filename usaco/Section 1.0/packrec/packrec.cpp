/*
ID: piotrek4
LANG: C++
TASK: packrec
*/


#include <fstream>
#include <iostream>
#define MAXN 4
#define INF 10000000
using namespace std;
int L,W,count=0,Min=INF; // count is the the index of answer that another optimum area should be added to
int perm[24][4] = {{0,1,2,3},{0,1,3,2},{0,2,1,3},{0,2,3,1},{0,3,1,2},{0,3,2,1},{1,0,2,3},{1,0,3,2},{1,2,0,3},{1,2,3,0},{1,3,0,2},{1,3,2,0},{2,0,1,3},{2,0,3,1},{2,1,0,3},{2,1,3,0},{2,3,0,1},{2,3,1,0},{3,0,1,2},{3,0,2,1},{3,1,0,2},{3,1,2,0},{3,2,0,1},{3,2,1,0}};//all the permutations of 1-4;
struct Rectangle 
{
	int w,l;
	bool operator() (Rectangle i,Rectangle j) { return (i.w<j.w);}
};
int max(int a,int b)
{
	return (a>b)?a:b;
}
int max3(int a, int b, int c)
{
	return max(max(a,b),c);
}
int max4(int a,int b, int c, int d)
{
	return max(max(max(a,b),c),d);
}
Rectangle rect[MAXN];
Rectangle answer[100];

void checks();
void check(int w, int l)//check if a given dimension has a smaller area. If so, make a new list, otherwise add it to the existing list
{
	
	Rectangle tmp; tmp.w=w,tmp.l=l;
	if (tmp.w==5&&tmp.l==8) checks();
	int area = tmp.l*tmp.w;
	if (tmp.w>tmp.l)
		{
			int tempW = tmp.w;
			tmp.w=tmp.l;
			tmp.l=tempW;
		}
	if (area<Min)//new optimum area
	{
		for (int i=0;i<count;i++)
			answer[i].w=0,answer[i].l=0;
		answer[0]=tmp;
		count =1;
		Min=area;
	}
	else if (area == Min)
	{
		for (int i=0;i<count;i++)//if this width is different from all other widths, then it is another variation of the minimum area.
		{
			if (answer[i].w==tmp.w)
				return;
		}
		int index=0;
		while ( answer[index].w!=0 && tmp.w>answer[index].w)
		{
			++index;
		}

		for (int i=count;i>index;--i)
			answer[i]=answer[i-1];

		answer[index]=tmp;
		count ++;
	}
}


Rectangle rotate(Rectangle in)
{
	Rectangle tmp;
	tmp.w=in.l;
	tmp.l=in.w;
	return tmp;
}
void checks()
{return;}
void getmin()
{
	for (int p=0;p<24;p++)
	{
		int o=perm[p][0],t=perm[p][1],th=perm[p][2],f=perm[p][3];
		Rectangle tmp;
		Rectangle one=rect[o],two=rect[t],three=rect[th],four=rect[f];
		for (int a=0;a<2;a++,one=rotate(one))
		{
			
			for (int b=0;b<2;b++,two=rotate(two))
			{
				for (int c=0;c<2;c++,three=rotate(three))
				{
					for (int d=0;d<2;d++,four=rotate(four))
					{
						//layout one
						int ow=one.w + two.w + three.w + four.w;
						int ol=max(max3(one.l,two.l,three.l),four.l);
						check(ow,ol);

						//layout two
						int tw=max(one.l,two.w+three.w+four.w);
						int tl=one.w+max3(two.l,three.l,four.l);
						check(tw,tl);

						//layout three
						int thw = four.w+max(one.l,two.w+three.w);
						int thl = max(four.l , one.w+max(two.l,three.l));
						check(thw,thl);

						//layout four
						int fw = one.w+max(two.w,three.w)+four.w;
						int fl = max3(one.l,two.l+three.l,four.l);
						check(fw,fl);

						//layout five
						int fiw = max(one.w,two.w) + three.w+four.w;
						int fil = max3(one.l+two.l,three.l,four.l);
						check(fiw,fil);

						//layout six
						int sw=one.w+four.w;

						if (one.l<four.l)
							sw=max(one.w+four.w,two.w+four.w);
						if (one.l+two.l>four.l)
							sw=max(sw,two.w+three.w);
						if (one.l>four.l)
							sw=max(sw,one.w+three.w);
						sw=max(max(sw,two.w),three.w);

						int sl = max(one.l+two.l,three.l+four.l);
						check(sw,sl);
						//end of layout six
					}//end of rotation four
				}//end of rotation three
			}//end of rotation two
		}//end of rotation one
	}
}


int main()
{
	ifstream fin("packrec.in");
	for (int i=0;i<MAXN;i++)
		fin >>rect[i].w >> rect[i].l;
	getmin();
	ofstream fout("packrec.out");
	fout<<answer[0].w*answer[0].l<<endl;
	for (int i=0;i<count;i++)
	{
		fout<<answer[i].w<<" " << answer[i].l<<endl;
	}


}
