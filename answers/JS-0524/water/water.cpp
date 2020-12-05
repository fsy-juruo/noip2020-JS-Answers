#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1;
	int s=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		s=s*10+(c-'0');
		c=getchar();
	}
	return f*s;
}
int n,m,t[100002],q[100002],ans[100002][2];//t存储每个节点排出管道的数量，q存储最终接收点的序号，ans存储每个节点所接收的水的体积 
vector<int>a[100002];//存储每个节点的汇集管道的序号 
int wdgcd(int x,int y){
	if(x%y==0)return y;
	return wdgcd(y,x%y);
}
void jiafa(int u,int fzl,int fml,int fzr,int fmr){
	int g=wdgcd(fml,fmr);
	int cl=fmr/g;
	int cr=fml/g;
	fzl*=cl,fzr*=cr,fml*=cl,fmr*=cr;
	int fz=fzl+fzr;
	int gn=wdgcd(fz,fml);
	ans[u][0]=fz/gn,ans[u][1]=fml/gn;
}
void dfs(int u){
	if(ans[u][0])return;
	if(!ans[u][1])ans[u][1]=1;
	if(u<=m)ans[u][0]=ans[u][1]=1;
	for(int i=0;i<a[u].size();++i){
		int v=a[u][i];
		dfs(v);
		jiafa(u,ans[u][0],ans[u][1],ans[v][0],ans[v][1]*t[v]);
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);

	n=read();
	m=read();
	for(int i=1;i<=n;++i){
		t[i]=read();
		//存储最终接收点 
		if(!t[i]){
			q[++q[0]]=i;
			continue;
		}
		//存储每个节点的汇集管道 
		for(int j=1;j<=t[i];++j){
			int v=read();
			a[v].push_back(i);
		}
	}
	
	for(int i=1;i<=q[0];++i){
		dfs(q[i]);
		cout<<ans[q[i]][0]<<' '<<ans[q[i]][1]<<endl;
	}
	
	return 0;
}

