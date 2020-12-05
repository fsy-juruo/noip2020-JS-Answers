#include<bits/stdc++.h>
#define N 100010
using namespace std;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline int gcd(int a,int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
int ans1[N],ans2[N];
inline void add(int v,int a,int b){
	if(ans1[v]==0&&ans2[v]==0){
		ans1[v]=a,ans2[v]=b;
		return;
	}
	ans1[v]=ans1[v]*b+ans2[v]*a;
	ans2[v]=ans2[v]*b;
	int gcd1=gcd(ans1[v],ans2[v]);
	ans1[v]/=gcd1,ans2[v]/=gcd1;
}
int n,m,a[N],ui[N];
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;++i)
		ans1[i]=ans2[i]=1;
	for(int i=1;i<=n;++i){
		ui[i]=read();
		for(int j=1,v;j<=ui[i];++j){
			v=read();
			if(ans1[i]){
				int a=ans1[i]*1;
				int b=ans2[i]*ui[i];
				add(v,a,b);
			}
		}
	}
	for(int i=1;i<=n;++i)
		if(ui[i]==0){
			int gcd1=gcd(ans1[i],ans2[i]);
			printf("%d %d\n",ans1[i]/gcd1,ans2[i]/gcd1);	
		}
	return 0;
}

