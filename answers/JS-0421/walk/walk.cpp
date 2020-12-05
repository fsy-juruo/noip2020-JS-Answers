#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define mo 1000000007
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);putchar('\n');
}
template<typename T> void chkmod(T &x,T y){x=(x+y>=mo)?(x+y-mo):(x+y);}
template<typename T> void chkmin(T &x,T y){x=x<y?x:y;}
int n,k;
int w[20];int now[20][2];
struct wzy{
	int ci,di;
}co[500010];
int ans=0;int a[20];int t[20];
inline void dfs(int dep){
	if(dep>k){
		rep(i,1,k)t[i]=a[i];
		int cnt=0;int now=0;
		while(1){
			now=now%n+1;t[co[now].ci]+=co[now].di;cnt++;
			if(t[co[now].ci]>w[co[now].ci]||t[co[now].ci]<1)break;
		}
		chkmod(ans,cnt);
	}else{
		rep(i,1,w[dep]){a[dep]=i;dfs(dep+1);}
	}
}

int f[100010];int dd[20];

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	read(n);read(k);
	rep(i,1,k)read(w[i]);
	rep(i,1,n){read(co[i].ci);read(co[i].di);dd[co[i].ci]+=co[i].di;}
	int tmp=1;
	rep(i,1,k)tmp&=(dd[i]==0);
	if(tmp){write(-1);return 0;}
	
	if(n<=100){dfs(1);write(ans);}
	else if(k==1){
		rep(i,1,w[1])f[i]=n+1;
		int dif=0;
		rep(i,1,n){
			dif+=co[i].di;
			if(dif<0&&dif>=-w[1])chkmin(f[-dif],i);
			if(dif>0&&dif<=w[1])chkmin(f[w[1]-dif+1],i);
		}
		int l=0;int r=w[1]+1;
		while(l<w[1]&&f[l+1]<=n)l++;
		while(r>1&&f[r-1]<=n&&r>=1)r--;
		
		int ans=0;
		rep(i,1,w[1]){
			if(f[i]<=n){chkmod(ans,f[i]);}
			else{
				if(dif<0){
					int cnt=(i-l)/(-dif)+((i-l)%(-dif)!=0);int pos=i+cnt*dif;
					int temp=(1ll*cnt*n)%mo;chkmod(temp,f[pos]);chkmod(ans,temp);
				}else{
					int cnt=(r-i)/dif+((r-i)%dif!=0);int pos=i+cnt*dif;
					int temp=(1ll*cnt*n)%mo;chkmod(temp,f[pos]);chkmod(ans,temp);
				}
			}
		}
		write(ans);
	}
	return 0;
}
/*
10 1
20
1 1
1 -1
1 1
1 1
1 -1
1 -1
1 1
1 1
1 1
1 1

*/
