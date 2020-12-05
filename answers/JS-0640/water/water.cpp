#include<bits/stdc++.h>
using namespace std;
inline int read(){
	   int x=0,f=1;char ch=getchar();
	   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	   while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	   return x*f;
}
vector<int> edge[100010];
long long fz[100010],fm[100010];
int fa[100010],vis[100010],ans[100010];
int gcd(int x,int y){
	int c;
	while(y!=0){
		c=x%y;
		x=y;
		y=c;
	}
	return x;
}
void dfs(int x){
	int w=edge[x].size();
	long long zg,zz,zz1;
	if(w==0){
		return ;
	}
	fm[x]*=w;
	for(int i=0;i<w;i++){
		int y=edge[x][i];
		zg=fm[x]*fm[y]/gcd(fm[x],fm[y]);
		zz=zg/fm[y];
		zz1=zg/fm[x];
		fm[y]=zg;
		fz[y]=fz[y]*zz+fz[x]*zz1;
		vis[y]++;
		if(vis[y]==fa[y]){
			dfs(y);
		}
	}
	return ;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m,d,cnt=0,x;
	long long z;
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		fz[i]=0;
		fm[i]=1;
		d=read();
		if(d==0){
			cnt++;
			ans[cnt]=i;
			continue;
		}
		for(int j=1;j<=d;j++){
			x=read();
			edge[i].push_back(x);
			fa[x]++;
		}
	}
	for(int i=1;i<=m;i++){
		fz[i]=1;
		dfs(i);
	}
	for(int i=1;i<=cnt;i++){
		z=gcd(fz[ans[i]],fm[ans[i]]);
		cout<<fz[ans[i]]/z<<" "<<fm[ans[i]]/z<<endl;
	}
	return 0;
}

