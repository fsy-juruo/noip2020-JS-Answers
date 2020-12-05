#include<bits/stdc++.h>
#define K 10+10
#define N 500000+10
using namespace std;
int n,k;
int w[K];
int c[N],d[N];
int bf[K];
int a[K];long long step;
void dfs(int v)
{
	if(v>k){
/*		
		return;
		
		for(int i=1;i<=k;++i)
		  cout<<a[i]<<' ';cout<<endl;		
		cout<<step<<endl;*/
		for(int i=1;i<=k;++i) bf[i]=a[i];
		while(1){
			for(int i=1;i<=n;++i)
			{
				step++;
				if(bf[c[i]]+d[i]<=w[c[i]]&&bf[c[i]]+d[i]>=1)
				  bf[c[i]]+=d[i];
				else return;
			}
		}
		
	}
	for(int i=1;i<=w[v];++i)
	  a[v]=i,dfs(v+1);
}
#define F "walk"//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int main(){
	freopen(F".in","r",stdin);
	freopen(F".out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;++i) cin>>w[i];
	for(int i=1;i<=n;++i) cin>>c[i]>>d[i];
	
	dfs(1);
	cout<<step%1000000007<<endl;
	return 0;
}

