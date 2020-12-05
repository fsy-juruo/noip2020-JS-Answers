#include<bits/stdc++.h>
#define F(i,a,b) for (int i=a;i<=b;i++)
#define DF(i,a,b) for (int i=a;i>=b;i--)
#define ms(a,b) memset(a,b,sizeof a)
#define LL long long
#define pb push_back
#define SZ(x) (int)x.size()-1
using namespace std;
inline int read(){
	int w=1,c=0; char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=5e5+10,mod=1e9+7;
int n,k,w[20],c[M],d[M];
int tmp[20],s[20];
int id(int tim){
	int ret=0;
	F(i,1,k){
		ret=ret+(tmp[i]-1)*s[i-1];
	}
	ret+=(tim-1)*s[k];
	ret++;
	return ret;
}
bool valid(){
	F(i,1,k){
		if (!tmp[i] || tmp[i]>w[i]) return 0;
	}
	return 1;
}
int to[M],nxt[M],head[M],cnt,de[M];
void add(int x,int y){
//		cout<<x<<" -> "<<y<<"\n";
	 to[++cnt]=y; nxt[cnt]=head[x]; head[x]=cnt;
}
void dfs(int x){
	if (x==k+1){
		F(i,1,n){
			int now=id(i);
			tmp[c[i]]+=d[i];
			if (valid()){
				int orr=id(i+1>n ? 1 : i+1);
				add(orr,now);
				de[now]++;
			}
			tmp[c[i]]-=d[i];
		}
		return ;
	}
	F(i,1,w[x]){
		tmp[x]=i;
		dfs(x+1);
	}
}
int q[M],dis[M];
int ans;
void getdfs(int x){
	if (x==k+1){
		int now=id(1);
		if (de[now]){
			puts("-1");
			exit(0);
		}
		ans=(ans+dis[now])%mod;
		return ;
	}
	F(i,1,w[x]){
		tmp[x]=i;
		getdfs(x+1);
	}
}
void solve_small(){
	dfs(1);
	int l=1,r=0;
	F(i,1,n*s[k]){
		if (!de[i]){
			dis[i]=1;
			q[++r]=i;
		}
	}
	while (l<=r){
		int x=q[l++];
		for (int i=head[x];i;i=nxt[i]){
			int y=to[i];
			de[y]--;
			dis[y]=dis[x]+1;
			q[++r]=y;
		}
	}
	ans=0;
	getdfs(1);
	cout<<ans<<"\n";
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(); k=read();
	s[0]=1; int mx=0;
	F(i,1,k) w[i]=read(),mx=max(mx,w[i]),s[i]=s[i-1]*w[i];
	F(i,1,n){
		c[i]=read(); d[i]=read();
//		t[d[i]]+=c[i];
	}
//	if (k==1){
////		solve_chain();
//		return 0;
//	}
	if (mx<=10 && k<=5){
		solve_small();
		return 0;
	}
	puts("-1");
	return 0;
}
/*
3 2
3 3
1 1
2 -1
1 1

2 1
3
1 1
1 -1
*/
