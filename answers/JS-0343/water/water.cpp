#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010

int n,m,de[MAXN];
bool vis[MAXN];
int head[MAXN],cnt=0;
struct edge{
	int to,N;
}edge[MAXN*6];

long long gcd(long long a,long long b){
	if(b==0) return a;
	return gcd(b,a%b);
}

struct cst{
	long long fm,fz;
	cst operator += (const cst &x){
		if(fz==0&&fm==0){
			fm=x.fm;
			fz=x.fz;
		}
		else{
			fz=fz*x.fm+x.fz*fm;
			fm*=x.fm;
			int t=gcd(fm,fz);
			fm/=t;
			fz/=t;			
		}
		return *this;
	} 
}ans[MAXN];

void add_edge(int u,int v){
	cnt++;
	edge[cnt].to=v;
	edge[cnt].N=head[u];
	head[u]=cnt;
}

int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}

void SPFA(int s){
	queue <int>q;
	for(int i=1;i<=n;i++) vis[i]=false;
	q.push(s);
	vis[s]=true;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=false;
		cst tem=ans[u];
		tem.fm*=de[u];
		for(int i=head[u];i;i=edge[i].N){
			int v=edge[i].to;
			ans[v]+=tem;
			if(!vis[v]){
				vis[v]=true;
				q.push(v);				
			}
		}
	}
}

void readp(){
	memset(head,0,sizeof(head));
	n=read();m=read();
	for(int i=1;i<=n;i++){
		de[i]=read();
		int v;
		for(int j=1;j<=de[i];j++){
			v=read();
			add_edge(i,v);
		}
	}
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	readp();
	ans[1].fm=1;
	ans[1].fz=1;
	for(int i=1;i<=m;i++)
		SPFA(i);
	for(int i=1;i<=n;i++)
		if(de[i]==0) cout<<ans[i].fz<<" "<<ans[i].fm<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
