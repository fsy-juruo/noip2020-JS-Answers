//bothes' regards
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define maxn 1000010
inline int read()
{
	char c;int sign=1;
	while((c=getchar())<'0'||c>'9') if(c=='-') sign=-1;
	int ret=c-'0';
	while((c=getchar())>='0'&&c<='9') ret=ret*10+c-'0';
	return ret*sign;
}
stack<int>st1;
stack<int>st2;
stack<int>st3;
int n,m;
struct node
{
	int x,y;
};
vector<node>l;
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read();
	m=read();
	int vis1=0;
	int a1=0;
	int a11=0;
	int a2=0;
	int a22=0;
	int vis2=0;
	int a3=0;
	for(int i=1;i<=m;i++)
	{
		int x=read();
		st1.push(x);
		if(i==1)
		{
			a1=x;
		}
		if(x!=a1&&vis1==0)
		{
			a11=x;
			vis1=1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int x=read();
		st2.push(x);
		if(i==1)
		{
			a2=x;
		}
		if(x!=a2&&vis2==0)
		{
			a22=x;
			vis2=1;
		}
	}
	int cnt1=0;
	int cnt2=0;
	int cnt3=0;
	cnt1=3;
	cnt2=3;
	if(a1==a2)
	{
		if(a1==1)
		{
			a3=2;
			while(st1.top()==2)
			{
				st1.pop();
				st3.push(2);
				cnt3++;
				cnt1--;
				node xx;
				xx.x=1;
				xx.y=3;
				l.push_back(xx);
			//	cout<<xx.x<< " "<<xx.y<<endl;
				
			}
			while(st2.top()==2)
			{
				st2.pop();
				st3.push(2);
				cnt3++;
				cnt2--;
				node xx;
				xx.x=2;
				xx.y=3;
				l.push_back(xx);
			//	cout<<xx.x<< " "<<xx.y<<endl;
			}
			if(cnt1==1)
			{
				for(int i=1;i<=cnt2;i++)
				{
					node xx;
					xx.x=2;
					xx.y=1;
					l.push_back(xx);
				}
				cnt1=3;
				if(cnt1==3)
				{
					int k=l.size();
					cout<<k<<endl;
					for(int i=0;i<l.size();i++)
					{
						node xx=l[i];
						cout<<xx.x<< " "<<xx.y<<endl;
					}
				}
				
			}
		}
		if(a1==2)
		{
			a3=1;
		}
		
	}
	return 0;
}
