#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define LL long long
const int N=5e5+5;
const int MOD=1e9+7;

int n,k;
int w[12];
int a[N],b[N];
LL ans;

vector<vector<int> > al;
void dfs1(vector<int> v,int dep)
{
	if(dep==k+1) {al.pb(v); return;}
	for(int i=1;i<=w[dep];i++)
	{
		vector<int> vv=v;
		vv.pb(i); dfs1(vv,dep+1);
	}
}
void func1()
{
	vector<int> v;
	v.clear();
	dfs1(v,1);
	for(int i=0;i<al.size();i++)
	{
		v=al[i];
		while(1)
		for(int j=1;j<=n;j++)
		{
			v[a[j]-1]+=b[j]; ans++;
			if(v[a[j]-1]<=0 || v[a[j]-1]>w[a[j]] || ans==1e8) goto end;
		}
		end: ;
	}
	if(ans>=2e7) ans=-1;
	printf("%d\n",ans);
}

int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
		scanf("%d",w+i);
	for(int i=1;i<=n;i++)
		scanf("%d%d",a+i,b+i);
	func1();
	
	return 0;
}
