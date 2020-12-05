#include<bits/stdc++.h>
#define ll long long
#define gc() getchar()
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=gc();int neg=1;
	for(;!isdigit(c);c=gc())if(c=='-')neg=-1;
	for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+c-'0';
	x*=neg;
}
const int maxn=5e5+10;
const int p=1e9+7;
int n,k;
int s[15];
int start[15];
int cur[15];
struct move{
	int w,d;
}m[maxn];
int ans;
int flag;
int curclock=clock();
namespace solven5{
	void dfs(int step,int cnt){
		if(clock()-curclock>=950000){
			flag=1;
		}
		if(flag){
			return;
		}
//		cout<<step<<" "<<cnt<<" ";
//		for(int i=1;i<=k;i++){
//			cout<<cur[i]<<" ";
//		}
//		cout<<endl;
		move nxt=m[step];
//		cout<<nxt.w<<" "<<nxt.d<<endl;
		cur[nxt.w]+=nxt.d;
		if(cur[nxt.w]>s[nxt.w]||cur[nxt.w]<1){
			ans=(ans+cnt+1)%p;
			return;
		}
		dfs(step%n+1,cnt+1);
	}
}
void getstart(int curk,int k){
	if(flag){
		return;
	}
	if(curk==k+1){
		for(int i=1;i<=k;i++){
//			cout<<start[i]<<" ";
			cur[i]=start[i];
		}
//		cout<<endl;

		solven5::dfs(1,0);
//		cout<<endl;
		return;
	}
	for(int i=1;i<=s[curk];i++){
		start[curk]=i;
		getstart(curk+1,k);
		start[curk]=0;
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	read(n);read(k);
	int maxw=0;
	for(int i=1;i<=k;i++){
		read(s[i]);
		maxw=max(maxw,s[i]);
	}
	int w,d;
	for(int i=1;i<=n;i++){
		read(w);read(d);
		m[i]=(move){w,d};
	}
	getstart(1,k);
	if(!flag)cout<<ans%p<<endl;
	else cout<<-1<<endl;
	return 0;
}

