#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N=1e5+10;
const int M=1e6+10;
int n,m,deg[N];
int tot,head[N],ver[M],nxt[M],d[N];
void add(int x,int y){
	nxt[++tot]=head[x];
	head[x]=tot;
	ver[tot]=y;
}
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
queue<int>q;
int shui[N];
struct ans{
	int wat,num;
}a[N];
int gcd(int x,int y){
	if(y==0)return x;
	return gcd(y,x%y);
}
bool cmp(ans x,ans y){
	return x.num<y.num;
}
signed main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(),m=read();
	m=0;
	for(int i=1;i<=n;i++){
		d[i]=read();
		for(int j=1;j<=d[i];j++){
			int x=read();
			add(i,x);
			deg[x]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(!deg[i]){
			shui[i]=604661760000000000llu;
			q.push(i);
		}
	}
	while(q.size()){
		int x=q.front();
		q.pop();
		if(!head[x]){
			a[++m].wat=shui[x];
			a[m].num=x;
		}
		for(int i=head[x];i;i=nxt[i]){
			int y=ver[i];
			deg[y]--;
			shui[y]+=shui[x]/d[x];
			if(!deg[y])q.push(y);
		}
		shui[x]=0;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		int tmp=gcd(a[i].wat,604661760000000000llu);
		printf("%llu %llu\n",a[i].wat/tmp,604661760000000000llu/tmp);
	}
	return 0;
}

