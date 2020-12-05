#include<bits/stdc++.h>
using namespace std;
struct pipe{
	int a1,a2;//分子,分母
	int t;//排出管道数量
	int tt[5];//排出管道编号 
	bool out;
};
pipe q[100001];
void work(int x)
{
	if(q[x].t!=0){
		for(int i=0;i<q[x].t;i++)
	{
		q[q[x].tt[i]].a1=     q[x].a2*q[x].t   *  q[q[x].tt[i]].a1   +   q[x].a1  *  q[q[x].tt[i]].a2   ;
		q[q[x].tt[i]].a2*=q[x].a2*q[x].t;
	} 
	}
	
}
int gcd(int a,int b)
{
	if(b==0) return a;
	 return gcd(b,a%b);
}
int main()
{
	
	int n,m,r;
	ifstream fin;
	fin.open("water.in") ;
	fin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		q[i].a1=0;q[i].a2=1;
		q[i].out =false;
		fin>>q[i].t;
		if(q[i].t==0) q[i].out=true;
		for(int j=0;j<q[i].t;j++)
		{
			fin>>q[i].tt[j];
		}
		
	}
	for(int i=1;i<=m;i++)
	{
		q[i].a1=1;q[i].a2=1;
	}	
	for(int i=1;i<=n;i++)
		work(i);
	
	ofstream fout;
	fout.open("water.out");
	for(int i=1;i<=n;i++)
	{
	if(q[i].out ==true)
	{
		r=gcd(q[i].a1,q[i].a2);
		fout<<q[i].a1/r <<" "<<q[i].a2/r<<endl;
	}
		
	}
}

