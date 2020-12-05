#include<bits/stdc++.h>
using namespace std;
int n,m,k,tot;
int mp[55][405];
int cnt[55];
int ans[10005][3];
int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
bool check()
{
	for(int i=1;i<=n+1;i++)
		for(int j=1;j<=cnt[i];j++)
			if(mp[i][j]!=mp[i][1]) return false;
	return true;
}
bool ff(int x,int y)
{
	if(cnt[x]<1||cnt[y]+1>m) return false;
	return true;
}
void move(int x,int y)
{
//	cout<<"x="<<x<<"  y="<<y<<endl;
//	cout<<"1:"<<mp[y][cnt[y]]<<' '<<mp[x][cnt[x]]<<endl;
	mp[y][cnt[y]+1]=mp[x][cnt[x]];
	mp[x][cnt[x]]=0;
	cnt[x]--;
	cnt[y]++;
	tot++;
	k++;
//	cout<<"2:"<<mp[y][cnt[y]]<<' '<<mp[x][cnt[x]]<<endl;
	ans[k][1]=x,ans[k][2]=y;
}
void jc()
{
	for(int i=1;i<=n+1;i++)
	{
		for(int j=1;j<=cnt[i];j++)
			cout<<mp[i][j]<<' ';
		cout<<endl;
	}
}
void hh(int a,int b,int dep)
{
	if(dep>820000) return;
	if(check())
	{
		k=dep;
		cout<<dep<<endl;
		return;
	}
	move(a,b);
	if(mp[1][cnt[1]]==mp[2][cnt[2]])
	{
		if(ff(1,2)&&(a!=2&&b!=1)) hh(1,2,dep+1);
		if(ff(2,1)&&(a!=1&&b!=2)) hh(2,1,dep+1);
	}
	if(mp[1][cnt[1]]==mp[3][cnt[3]])
	{
		if(ff(1,3)&&(a!=3&&b!=1)) hh(1,3,dep+1);
		if(ff(3,1)&&(a!=1&&b!=3)) hh(3,1,dep+1);
	}
	if(mp[2][cnt[2]]==mp[3][cnt[3]])
	{
		if(ff(2,3)&&(a!=3&&b!=2)) hh(2,3,dep+1);
		if(ff(3,2)&&(a!=2&&b!=3)) hh(3,2,dep+1);
	}
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
	    	mp[i][j]=read();
	    cnt[i]=m;
	}
	move(1,3);
	while(!check())
	{
		if(mp[1][cnt[1]]==mp[2][cnt[2]])
		{
			if(ff(1,2)) {move(1,2);continue;}
			if(ff(2,1)) {move(2,1);continue;}
		}
		if(mp[1][cnt[1]]==mp[3][cnt[3]])
		{
			if(ff(1,3)) {move(1,3);continue;}
			if(ff(3,1)) {move(3,1);continue;}
		}
		if(mp[2][cnt[2]]==mp[3][cnt[3]])
		{
			if(ff(2,3)) {move(2,3);continue;}
			if(ff(3,2)) {move(3,2);continue;}
		}
	}
    for(int i=1;i<=k;i++)
        cout<<ans[i][1]<<' '<<ans[i][2]<<endl;
	return 0;
}
