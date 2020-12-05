#include<bits/stdc++.h>
using namespace std;
#define Sf scanf
#define Pf printf
#define ll long long
#define Pii pair<int,int>
#define P2 pair
#define Sz size
#define Vct vector
#define Pb push_back
#define Cb make_pair
#define Fi first
#define Se second
#define Ins insert
#define Que queue
#define Fr front
#define Psh push
#define Pp pop
Vct<P2<int,Pii> >v;
char c[1048590];
int sz;
int g[260];
int cur[260];
struct seg
{
	int dat[2000005];
	int I()
	{
		for(int i=1;i<=2000000;i++)dat[i]=0;
	}
	int c(int a,int b,int l=1,int r=sz,int k=1)
	{
		if(r<a||b<l)return 0;
		//cout<<"+"<<a<<" "<<b<<" "<<l<<" "<<r<<" "<<k<<endl;
		if(a<=l&&r<=b)dat[k]++;
		else
		{
			c(a,b,l,(l+r)/2,k*2);
			c(a,b,(l+r)/2+1,r,k*2+1);
		}
		return 0;
	}
	int q(int x,int l=1,int r=sz,int k=1)
	{
		if(r<x||x<l)return 0;
		//cout<<"?"<<x<<" "<<l<<" "<<r<<" "<<k<<" "<<dat[k]<<endl;
		if(l==r)return dat[k];
		else
		{
			return dat[k]+q(x,l,(l+r)/2,k*2)+q(x,(l+r)/2+1,r,k*2+1);
		}
	}
}T;
vector<int>vd[1048590];
int MIAN()
{
	T.I();
	Sf("%s",c+1);
	sz=1;
	while(c[sz]!=0)sz++;
	sz--;
	v.clear();
	for(int i=0;i<256;i++)g[i]=0;
	for(int i=1;i<=sz;i++)
	{
		g[c[i]]++;
		if(g[c[i]]%2==1)g[0]++;
		if(g[c[i]]%2==0)g[0]--;
		v.Pb(Cb(g[0],Cb(0,i)));
		cur[i]=0;
		vd[i].clear();
	}
	for(int i=0;i<256;i++)g[i]=0;
	for(int i=sz;i>=1;i--)
	{
		g[c[i]]++;
		if(g[c[i]]%2==1)g[0]++;
		if(g[c[i]]%2==0)g[0]--;
		v.Pb(Cb(g[0],Cb(1,i)));
	}
	sort(v.begin(),v.end());
	cur[1]=0;
	for(int i=2;i<=sz;i++)
	{
		cur[i]=cur[i-1];
		while(c[cur[i]+1]!=c[i]&&cur[i]!=0)cur[i]=cur[cur[i]];
		if(c[cur[i]+1]==c[i])cur[i]++;
	}
	/*
	for(int i=1;i<=sz;i++)
	{
		cout<<cur[i]<<" ";
	}
	cout<<endl;
	*/
	for(int i=1;i<=sz;i++)
	{
		if(i%(i-cur[i])==0)cur[i]=i/(i-cur[i]);
		else cur[i]=1;
	}
	for(int i=1;i<=sz;i++)
	{
		for(int j=1;j*j<=cur[i];j++)
		{
			if(cur[i]%j==0)
			{
				if(j*j!=cur[i])
				{
					vd[i].Pb(i/(j));
					vd[i].Pb(i/(cur[i]/j));
				}
				else
				{
					vd[i].Pb(i/j);
				}
			}
		}
	}
	/*
	for(int i=1;i<=sz;i++)
	{
		cout<<i<<":"<<cur[i]<<":";
		for(int j=0;j<vd[i].Sz();j++)
		{
			cout<<vd[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	ll res=0;
	for(int i=0;i<v.Sz();i++)
	{
		if(v[i].Se.Fi==0)
		{
			//cout<<"!"<<v[i].Fi<<" "<<v[i].Se.Fi<<" "<<v[i].Se.Se<<endl;
			T.c(v[i].Se.Se+1,sz);
		}
		else
		{
			for(int j=0;j<vd[v[i].Se.Se-1].Sz();j++)
			{
				//cout<<">>"<<vd[v[i].Se.Se-1][j]<<endl;
				res+=(ll)T.q(vd[v[i].Se.Se-1][j]);
			}
			//cout<<">"<<v[i].Fi<<" "<<v[i].Se.Fi<<" "<<v[i].Se.Se<<" "<<res<<endl;
		}
	}
	Pf("%lld\n",res);
	/*
	for(int i=1;i<=sz;i++)
	{
		cout<<cur[i]<<" ";
	}
	cout<<endl;
	*/
	return 0;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	Sf("%d",&T);
	while(T--)MIAN();
	return 0;
}
