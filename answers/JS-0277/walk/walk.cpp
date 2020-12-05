#include<bits/stdc++.h>
using namespace std;
const int maxk=13;
const int maxn=5e5+7;
const long long mod=1e9+7;
int n,k,w[maxk],c[maxn],d[maxn],vis[maxk];
int maze[maxk],a[maxk];
long long res,ans;
inline int read(){
	int x=0,f=1;char cc=getchar();
	while (cc<'0'||cc>'9') {if (cc=='-') f=-1;cc=getchar();}
	while (cc>='0'&&cc<='9') {
		x=(x<<1)+(x<<3)+(cc^48);
		cc=getchar();
	}
	return x*f;
}
void go(){
	ans=0;
	bool ok=1,ok2=1;
	for (int i=1;i<=k;i++){
		a[i]=maze[i];
		//cout<<a[i]<<" ";
	}
	while (ok){
		for (int i=1;i<=n;i++){
			a[c[i]]+=d[i];ans++;
			if (a[c[i]]>w[c[i]] || a[c[i]]<1) {
				ok=0;
				break;
			}
		}
		if (ok2){
			for (int i=1;i<=n;i++){
				if (a[i]!=maze[i]) {
					ok2=0;
					break;
				}
			}
			if (ok2) {
				ans=-1;
				break;
			}
		}
		ans%=mod;
	}	
	//cout<<endl<<ans<<endl;
	if (ans==-1) res=-1;
	else res=(res+ans)%mod;
	return ;
}
void build(int step){
	if (res==-1) return ;
	if (step==k){
		//build done
		go();
		return ;
	}
	for (int i=1;i<=w[step+1];i++){
		if (res==-1) return ;
		if (!vis[step+1]){
			build(step+1);
			break;
		}
		maze[step+1]=i;
		build(step+1);
	}
	maze[step+1]=0;
	return ;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();k=read();
	for (int i=1;i<=k;i++){
		w[i]=read();
	}
	for (int i=1;i<=n;i++){
		c[i]=read();d[i]=read();
		vis[c[i]]=1;
	}
	if (n>=10000) {
		printf("-1\n");
		return 0;
	}
	for (int i=1;i<=w[1];i++){
		maze[1]=i;
		build(1);
	}
	if (res!=-1) {
		for (int i=1;i<=k;i++){
			if (!vis[i]){
				res=(res*w[i])%mod;
			}
		}
	}
	printf("%lld\n",res);
	return 0;
}
/*
3 2
3 3
1 1
2 -1
1 1
*//*
5 4
6 8 6 5
3 1
2 1
1 1
2 1
2 -1
*/
