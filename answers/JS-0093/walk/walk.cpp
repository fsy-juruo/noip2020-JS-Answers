#include <bits/stdc++.h>
using namespace std;
const int MAXN=500010;
int mod=1e9+7;
long long ans;
int n,k;
int w[11];
int a[MAXN][2];
int ma[11];
inline int re(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
int p[11],x[11];
inline bool check(){
	for(int i=1;i<=k;i++){
		if(x[i]>w[i]||x[i]<1)
		return true;
	}	
	return false;
}
inline void get(int d){
	if(d>k){
		for(int i=1;i<=k;i++){
			x[i]=p[i];
		}
		for(int stp=1;;stp++){
			int i=(stp-1)%n+1;
			x[a[i][0]]+=a[i][1];
			if(check()){
				ans=(ans+stp)%mod;
				break;
			}
		}
		return;
	}
	for(int i=1;i<=w[d];i++){
		p[d]=i;
		get(d+1);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=re(),k=re();
	for(int i=1;i<=k;i++) w[i]=re();
	for(int i=1;i<=n;i++) {
		int c=re(),d=re();
		a[i][0]=c;
		a[i][1]=d;
		ma[c]+=d;
	}
	bool p=true;
	for(int i=1;i<=k;i++){
		if(ma[i]!=0) p=false;
	}
	if(p){
		printf("-1");
		return 0;
	}
	get(1);
	cout<<ans;
	return 0;
}
/*
3 2
3 3
1 1
2 -1
1 1


5 4
6 8 6 5
3 1
2 1
1 1
2 1
2 -1

*/
