#include<bits/stdc++.h>
using namespace std;
struct poi
{
	int nu,ro[7];
	pair<int,int> fil;
}x[100010];
int dadd(int a,int b)
{
	int t;
	if(a<b)
		swap(a,b);
	while(b!=0)
	{
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
pair<int,int> cv(pair<int,int>x,pair<int,int> y)
{
	if(y.first==0)
		return x;
	if(x.first==0)
		return y;
	int x1=x.first,x2=x.second,y1=y.first,y2=y.second;
	int a=(x2*y2)/dadd(x2,y2);
	pair<int,int> dr;
	dr.first=x1*(a/x2)+y1*(a/y2);
	dr.second=a;
	int mm=dadd(dr.first,dr.second);
		dr.first/=mm;
		dr.second/=mm;
	return dr;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int i,n,m,j,t=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>x[i].nu;
		for(j=0;j<x[i].nu;j++)
		{
			cin>>x[i].ro[j];
		}
		if(i<=m)
		{
			x[i].fil.first=1;
			x[i].fil.second=1;
		}
		else
		{
			x[i].fil.first=0;
			x[i].fil.second=0;
		}
		
	}
	t=0;
	for(i=1;i<=n;i++)
	{
			pair<int,int> op;
			op.first=x[i].fil.first;
			op.second=x[i].fil.second*x[i].nu;
//			cout<<endl<<i<<":"<<endl;
			for(j=0;j<x[i].nu;j++)
			{
//				cout<<x[i].ro[j]<<"-"<<x[x[i].ro[j]].fil.first<<"&"<<x[x[i].ro[j]].fil.second<<"*"<<op.first<<"&"<<op.second;
				x[x[i].ro[j]].fil=cv(x[x[i].ro[j]].fil,op);
//				cout<<"("<<x[x[i].ro[j]].fil.first<<"*"<<x[x[i].ro[j]].fil.second<<")"<<endl;
			}
		
	}
	for(i=1;i<=n;i++)
	{
		if(x[i].nu==0)
			cout<<x[i].fil.first<<" "<<x[i].fil.second<<endl;
	}
	return 0;
}
