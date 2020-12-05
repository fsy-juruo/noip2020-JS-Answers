#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int M=4500007;
int n,m,d,a;
int cnt,head[M],to[M],last[M],inde[M],son[M],ed[M];
ull fm[M],fz[M];

inline int read(){
	char ch;
	int x=0,f=1;
	ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}

void makemap(int u,int v){
	to[++cnt]=v;
	last[cnt]=head[u];
	head[u]=cnt;
}

void add(int u,int v){
	if(fz[v]==0){
		fz[v]=fz[u];
		fm[v]=fm[u]*son[u];
		return;
	}
	fz[v]=fm[v]*fz[u]+fz[v]*fm[u]*son[u];
	fm[v]=fm[u]*fm[v]*son[u];
	ull a=fz[v],b=fm[v];
	ull c=b%a;
	while(c){
		b=a;
		a=c;
		c=b%a;
	}
	fz[v]/=a;
	fm[v]/=a;
}

void dfs(int u){
	for(int i=head[u];i;i=last[i]){
		int v=to[i];
		add(u,v);
		if(son[v]) dfs(v);
	}
	fz[u]=0;
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(); m=read();
	for(int i=1;i<=n;i++){
		d=read();
		if(d==0) ed[i]=1;
		for(int j=1;j<=d;j++){
			a=read();
			makemap(i,a);
			inde[a]++;
			son[i]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(inde[i]==0){
			fz[i]=fm[i]=1; 
			dfs(i);
			fz[i]=0;
		}
	}
	for(int i=1;i<=n;i++)
		if(ed[i]) cout<<fz[i]<<' '<<fm[i]<<endl;
	return 0;
}

