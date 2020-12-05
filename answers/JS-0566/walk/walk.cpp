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
int n,m;
int w[105];
vector<Pii>v;
int cur[5];
ll res=0;

int func()
{
	vector<int>t;
	for(int i=1;i<=m;i++)
	{
		t.Pb(cur[i]);
	}
	ll g=0;
	//cout<<"!";
	bool de=1;
	while(de)
	{
		g++;
		//for(int i=0;i<t.Sz();i++)cout<<t[i]<<" ";
		//cout<<endl;
		t[v[(g-1)%n].Fi-1]+=v[(g-1)%n].Se;
		de=0;
		for(int i=1;i<=m;i++)
		{
			if(t[i-1]<1||t[i-1]>w[i])de=1;
		}
		if(de)return g;
		de=0;
		for(int i=1;i<=n;i++)
		{
			if(cur[i]!=t[i-1])de=1;
		}
	}
	return -1;
}
int ypa(int k)
{
	if(k==m+1)
	{
		ll t=func();
		if(t<0)return -1;
		res+=func();
	}
	for(int i=1;i<=w[k];i++)
	{
		cur[k]=i;
		if(ypa(k+1)==-1)return -1;
	}
	return res;
}
int main()
{
	
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	Sf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		Sf("%d",&w[i]);
	}
	int x,y;
	for(int i=1;i<=n;i++)
	{
		Sf("%d%d",&x,&y);
		v.Pb(Cb(x,y));
	}
	cout<<ypa(1);
	return 0;
}
