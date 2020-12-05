#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
#define pb push_back
#define INF 2147483647
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=500005;
const int mod=1e9+7;
int n,k,w[15],c[Maxn],d[Maxn];
int nxt[100005],dist[100005];
int LP[100005],RP[100005];
int X[15];
void Add(int &x,int y){
	x+=y;
	if (x>=mod) x-=mod;
}
int dfs(int x){
	if (dist[x]==-2){
		printf("-1\n");
		exit(0);
	}
	if (dist[x]!=-1){
		return dist[x];
	}
	
	
	dist[x]=-2;
	int v=dfs(nxt[x])+n;
	if (v>=mod) x-=mod;
	return dist[x]=v;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();k=read();
	int Mx=0;
	for (int i=0;i<k;i++) w[i]=read(),Mx=max(Mx,w[i]);
	for (int i=0;i<n;i++){
		c[i]=read();d[i]=read();c[i]--;
	}
	if (Mx<=10){
		int T=1;
		for (int i=0;i<k;i++) T=T*w[i];
		for (int i=0;i<T;i++){
			dist[i]=-1;
			int tmp=i;
			for (int j=k-1;j>=0;j--) X[j]=tmp%w[j],tmp/=w[j];
			
			
			for (int j=0;j<n;j++){
				X[c[j]]+=d[j];
				if (X[c[j]]<0 || X[c[j]]>=w[c[j]]){
					nxt[i]=-1;
					dist[i]=j+1;
					break;
				}
			}
			if (nxt[i]==-1) continue;
			tmp=0;
			for (int j=0;j<k;j++){
				tmp=tmp*w[j]+X[j];
			}
			nxt[i]=tmp;
		}
		int ans=0;
		for (int i=0;i<T;i++){
			Add(ans,dfs(i));
		}
		printf("%d\n",ans);
		return 0;
	}
	
	if (k==1){
		int W=w[0],tt=0,Mx=0,Mn=0;
		for (int i=0;i<=100000;i++) LP[i]=RP[i]=1e9;
		for (int i=0;i<n;i++){
			tt+=d[i];
			if (tt>Mx){
				Mx=tt;
				RP[Mx]=i+1;
			}
			if (tt<Mn){
				Mn=tt;
				LP[-Mn]=i+1;
			}
		}
		
		for (int i=0;i<W;i++){
			int lo=i+1,hi=W-i;
			if (LP[lo]==1e9 && RP[hi]==1e9){
				nxt[i]=i+tt;dist[i]=-1;
			}
			else{
				nxt[i]=-1;dist[i]=min(LP[lo],RP[hi]);
			}
		}
		int ans=0;
		for (int i=0;i<W;i++){
			Add(ans,dfs(i));
		}
		printf("%d\n",ans);
		return 0;
	}
}
