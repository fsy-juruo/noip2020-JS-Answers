#include<bits/stdc++.h>
using namespace std;
#define reg register
typedef long long ll;
const int N=55,M=405,P=998244353;
inline int read(){
	int x=0,f=1;char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') f=0;
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?x:-x;
}
int n,m,f[N][M],col[N],mx,ansx[820005],ansy[820005],ans=-1;
ll pwm[M],pwn[N];
bool flag,vis[P+5];
inline int max(int a,int b){
	return a>b?a:b;
}
inline int g(){
	reg int res=0;
	for(reg int i=1;i<=n;i++){
		for(reg int j=1;j<=n;j++) col[j]=0;
		for(reg int j=1;j<=f[i][0];j++) col[f[i][j]]++;
		mx=0;
		for(reg int j=1;j<=n;j++) mx=max(mx,col[j]);
		res+=f[i][0]-mx;
	}
	return res;
}
void write(int x){
	if(x>10) write(x/10);
	putchar(x%10+'0');
}
inline ll mul(){
	ll cnt=0,tot=0;
	for(reg int i=1;i<=n+1;i++){
		cnt=0;
		for(reg int j=1;j<=m;j++)
			cnt=(cnt+pwm[j-1]*f[i][j])%P;
		tot=(tot+cnt*pwn[i-1])%P;
	}
	return tot;
}
inline bool check(){
	for(reg int i=1;i<=n;i++){
		if(!f[i][0]) continue;
		if(f[i][0]!=m) return 0;
		for(reg int j=2;j<=m;j++)
			if(f[i][j]!=f[i][j-1]) return 0;
	}
	return 1;
}
void dfs(int sum){
	reg int k=mul();
	if(vis[k]) return;vis[k]=1;
	if(sum+g()>820000) return;
	if(check()){
		flag=1;ans=sum;
		return;
	}
	for(reg int i=1;i<=n+1;i++){
		if(!f[i][0]) continue;
		for(reg int j=1;j<=n+1;j++){
			if(i==j||f[j][0]==m) continue;
			f[j][++f[j][0]]=f[i][f[i][0]--];
			dfs(sum+1);
			if(flag){
				ansx[sum]=i,ansy[sum]=j;return;
			}
			f[i][++f[i][0]]=f[j][f[j][0]--];
		}
	}
}
int main()
{
	freopen("ball.in","r",stdin);freopen("ball.out","w",stdout);
	n=read(),m=read();
	pwm[0]=pwn[0]=1;
	for(reg int i=1;i<=m;i++) pwm[i]=pwm[i-1]*m%P;
	for(reg int i=1;i<=n;i++) pwn[i]=pwn[i-1]*n%P;
	for(reg int i=1;i<=n;i++){
		f[i][0]=m;
		for(reg int j=1;j<=m;j++)
			f[i][j]=read();
	}
	dfs(0);
	write(ans);puts("");
	for(reg int i=0;i<ans;i++){
		write(ansx[i]);putchar(' ');write(ansy[i]);puts("");
	}
	return 0;
}
