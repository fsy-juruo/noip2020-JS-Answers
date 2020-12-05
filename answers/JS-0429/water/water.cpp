#include <bits/stdc++.h>
using namespace std;
long long fm[100010],zs,fz[100010],p[100010],l[100010],n,m,t,lf[2400010],pre[100010],l1[100010];
int gcd(int a,int b)
{
	if (a<b) swap(a,b);
	if (a%b==0)
	return b;
	else return gcd(b,a%b);
}
int lcm(int a,int b){
return a*b/gcd(a,b);}
void dd(int x,int y,int fs)
{
	if (fz[y]==0)
	{
		fz[y]=fz[x];
		fm[y]=fm[x]*fs;
		int o=gcd(fm[y],fz[y]);
		fz[y]/=o;
		fm[y]/=o;
	}
	else
	{
		int q=lcm(fm[y],fm[x]*fs);
		int o=q/fm[y]*fz[y]+q/fm[x]/fs*fz[x];
		int l=gcd(o,q);
		fz[y]=o/l;
		fm[y]=q/l;
	}
}
void dfs(int u)
{
	for (int i=1;i<=p[u];i++)
	  {
	  	int f=i+pre[u];
	  	dd(u,lf[f],p[u]);
	  	l[lf[f]]--;
	  	if (l[lf[f]]==0)
		  dfs(lf[f]); 
	}
	if (p[u]!=0)
	{
		fz[u]=0;fm[u]=0;
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	  {
	  	cin>>p[i];
	  	pre[i]=t;
	  	for (int j=1;j<=p[i];j++)
	  	  {
			t++;
			cin>>lf[t];
			l[lf[t]]++;
			l1[lf[t]]++;
			}
	  }
	for (int i=1;i<=m;i++)
	{
		fz[i]=1;
		fm[i]=1;
		for (int i=1;i<=t;i++)
		  l[lf[i]]=l1[lf[i]];
		dfs(i);
	}
	
	for (int i=1;i<=n;i++)
	  if (p[i]==0) 
	   if (fz[i]==0) cout<<0<<endl; 
	   else
	  cout<<fz[i]<<" "<<fm[i]<<endl;
	return 0;
}

