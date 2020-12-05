#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair <int,int>
#define fi fitst
#define se second
#define pb push_back
#define mem(x,v) memset(x,v,sizeof(x))

const int N=1e5+5;
const int inf=1e9+7;
const int mod=998244353;

int n,c[N],d[N],k,ans,w[15],ch[15],p[15];

void dfs(int id){
	if(id>k){
		int cnt=0,il=0;
		for(int i=1;i<=k;i++)p[i]=ch[i];
		for(int i=1;i<=n;i++){
			p[c[i]]+=d[i],cnt++;
			if(p[c[i]]<=0||p[c[i]]>w[c[i]]){
				il=1; break;
			}
		} bool same=1;
		for(int i=1;i<=k;i++)same&=(p[i]==ch[i]);
		if(same&&!il)puts("-1"),exit(0);
		else if(!il){
			int i=1;
			while(1){
				cnt++,p[c[i]]+=d[i];
				if(p[c[i]]<=0||p[c[i]]>w[c[i]])break;
				i=i%n+1;
			}
		} ans+=cnt;
		return;
	}
	for(int i=1;i<=w[id];i++)
		ch[id]=i,dfs(id+1);
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++)cin>>w[i];
	for(int i=1;i<=n;i++)cin>>c[i]>>d[i];
	dfs(1),cout<<ans<<endl;
	return 0;
}
/*
5 4
6 8 6 5
3 1
2 1
1 1
2 1
2 -1
*/
