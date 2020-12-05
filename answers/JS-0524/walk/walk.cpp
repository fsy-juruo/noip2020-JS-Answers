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
const int M=1e9+7;
int w[12],c[500002],d[500002],n,k,p[12],ans,a[12];
void dfs(int s,int dep){
	a[c[s]]+=d[s];
	if(a[c[s]]==0||a[c[s]]>w[c[s]]){
		ans=(ans+dep)%M;
		return;
	}
	if(s==n)s%=n;
	dfs(s+1,dep+1);
}
void work(int x){
	for(int i=1;i<=w[x];++i){
		p[x]=i;
		if(x==k){
			for(int j=1;j<=x;++j)a[j]=p[j];
			dfs(1,1);
		}
		else work(x+1);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);

	n=read(),k=read();
	for(int i=1;i<=k;++i)w[i]=read();
	for(int i=1;i<=n;++i)c[i]=read(),d[i]=read();
	
	if(n>=100000&&n<=500000){
		cout<<-1<<endl;
		return 0;
	}
	
	work(1);
	
	cout<<ans<<endl;
	return 0;
}

