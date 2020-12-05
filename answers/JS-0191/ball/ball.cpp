#include<bits/stdc++.h>
using namespace std;
struct tall{
	int num;
	int b[500];
};
tall t[60];
int k=0;
void pai(int);
int main()
{
	int n,m;
	ifstream fin;
	fin.open("ball.in");
	fin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		t[i].num=m;
		for(int j=1;j<=m;j++)
		fin>>t[i].b[j];
	}
	ofstream fout;
	fout.open("ball.out");
	for(int x=1;x<=n;x++)
	{
		int u=1;
	while(t[x].b[u]!=x)
	{
		if(t[t[x].b[u]].b[1]!=t[x].b[u])
		{
			for(int l=1;l<=u-1;l++)
			{
				fout<<t[x].b[u]<<n+1;k++;
			}
			
			for(int l=1;l<=m-u+1;l++)
			{
				fout<<x<<n+1;k++;
			}
			for(int l=1;l<=m-u+1)
			{
				fout<<t[x].b[u]<<x;k++;
			}
			fout<<n+1<<t[x].b[u];
			fout<<n+1<<t[x].b[u];
			fout<<n+1<<t[x].b[u];
			fout<<n+1<<t[x].b[u];
			k=k+4;
			for(int l=0;l<m-u+1;l++)
			{
				t[m+1].b[1+l]=t[t[x].b[u]].b[1+l];
				t[t[x].b[u]].b[1+l]=t[x].b[u+l];
			}
			for(int l=0;l<m-u+1;l++)
			{
				t[x].b[u+l]=t[m+1].b[m-u+1];
			}
			
			
		}
	}
	u++;
	}
	
}

