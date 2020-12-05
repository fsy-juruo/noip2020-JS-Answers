#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
using namespace std;
const long long mod=1e9+7;
template <typename T>inline void read(T &x){
	x=0;int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
template <typename T>inline void write(T x){
	ull y=0;ull t=x;int l=0;
	if(x<0){putchar('-');x++;t=-x;t++;}
	if(!t){putchar('0');return;}
	while(t){y=y*10+t%10;t/=10;l++;}
	while(l){putchar(y%10+'0');y/=10;l--;}
}
template <typename T>inline void writes(T x){
	write(x);
	putchar(' ');
}
template <typename T>inline void writeln(T x){
	write(x);
	puts("");
}
long long ans=0;
int w[6];int n,k;
int now[6];
int stp[110][2];
long long wz[11][11][11][11][11];
bool vis[11][11][11][11][11];
bool vis2[11][11][11][11][11];
int flag=0;
bool check(){
	for(int i=1;i<=k;i++){
		if(now[i]<1||now[i]>w[i])return false;
	}
	return true;
}
long long dfs2(){
	long long res=0;
	if(vis[now[1]][now[2]][now[3]][now[4]][now[5]]){
		return wz[now[1]][now[2]][now[3]][now[4]][now[5]];
	}
	vis2[now[1]][now[2]][now[3]][now[4]][now[5]]=true;
	int s[6];
	for(int i=1;i<=5;i++){
		s[i]=now[i];
	}
	
		for(int i=1;i<=n;i++){
			now[stp[i][0]]+=stp[i][1];wz[s[1]][s[2]][s[3]][s[4]][s[5]]++;wz[s[1]][s[2]][s[3]][s[4]][s[5]]%=mod;
			if(!check()){
				vis[s[1]][s[2]][s[3]][s[4]][s[5]]=true;return wz[s[1]][s[2]][s[3]][s[4]][s[5]];
			}
		}
		if(vis2[now[1]][now[2]][now[3]][now[4]][now[5]]){
			flag=1;
			return 0;
		}
		
		
		wz[s[1]][s[2]][s[3]][s[4]][s[5]]=(wz[s[1]][s[2]][s[3]][s[4]][s[5]]+dfs2())%mod;vis[s[1]][s[2]][s[3]][s[4]][s[5]]=true;return wz[s[1]][s[2]][s[3]][s[4]][s[5]];
	
}
void dfs(int x){
	if(x>k){
		dfs(x-1);return;
	}
	int q[6];
	if(x==0){
		for(int i=1;i<=k;i++){
			q[i]=now[i];
		}
		ans=(ans+dfs2())%mod;
		memset(vis2,0,sizeof(vis2));
		if(flag==1)return;
		for(int i=1;i<=k;i++){
			now[i]=q[i];
		}
		return;
	}
	for(int i=1;i<=w[x];i++){
		now[x]=i;
		dfs(x-1);
		if(flag==1)return;
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	
	read(n),read(k);
	for(int i=1;i<=k;i++){
		read(w[i]);
	}
	for(int i=1;i<=n;i++){
		read(stp[i][0]);
		read(stp[i][1]);
	}
	dfs(5);
	if(flag==1){
		writeln(-1);
		return 0;
	}
	writeln(ans);
	return 0;
}


