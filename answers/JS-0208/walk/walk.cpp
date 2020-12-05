#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
typedef unsigned long long ull;
const int INF=2147483647;
typedef vector<int> vi;
typedef priority_queue<int> pi;
typedef priority_queue<int,greater<int>,vi> pir;
const int N=5e5+10;
const int MOD=1000000007;

inline int read(){
	int x=0;
	int neg=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') neg=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*neg;
}

int n,k;
int w[15];
int c[N],d[N];
int maxn[15],minn[15],last[15];

inline void Input(){
	n=read();
	k=read();
	for(int i=0;i<k;i++) w[i]=read();
	for(int i=0;i<n;i++){
		c[i]=read()-1;
		d[i]=read();
	}
}

inline void Init(){
	for(int i=0;i<k;i++){
		int cur=0;
		maxn[i]=minn[i]=0;
		for(int j=0;j<n;j++){
			if(c[j]==i){
				cur+=d[j];
				if(d[j]>0) maxn[i]=max(maxn[i],cur);
				else minn[i]=min(minn[i],cur);
			}
		}
		last[i]=cur;
//		printf("%d : maxn[%d]=%d	minn[%d]=%d	last[%d]=%d\n",i,i,maxn[i],i,minn[i],i,last[i]);
	}
}

inline void Solve(){
	int ans=0;
	if(k==1){
		for(int i=1;i<=w[0];i++){
			int round=0,cur=i;
			for(;;round++){
				if(cur+maxn[0]>w[0]) break;
				if(cur<minn[0]+1) break;
				cur+=last[0];
			}
			int step=0;
			for(;step<n;step++){
				cur+=d[step];
				if(cur>w[step]) break;
				if(cur<0) break;
			}
			ans+=round*n+step;
			ans%=MOD;
		}
	} else if(k==2){
		for(int i=1;i<=w[0];i++){
			for(int j=1;j<=w[1];j++){
				int round=0,x1=i,x2=j;
				for(;;round++){
					if(x1+maxn[0]>w[0]) break;
					if(x1+minn[0]<1) break;
					if(x2+maxn[1]>w[1]) break;
					if(x2+minn[1]<1) break;
					x1+=last[0];
					x2+=last[1];
				}
				int step=0;
				for(;step<n;step++){
					x1+=d[step];
					if(x1>w[0]) break;
					if(x1<1) break;
					if(x2>w[1]) break;
					if(x2<1) break;
				}
				ans+=round*n+step;
			}
		}
	} else if(k==3){
		for(int i=1;i<=w[0];i++){
			for(int j=1;j<=w[1];j++){
				for(int k1=1;k1<=w[1];k1++){
					int round=0,x1=i,x2=j,x3=k1;
					for(;;round++){
						if(x1+maxn[0]>w[0]) break;
						if(x1<minn[0]+1) break;
						if(x2+maxn[1]>w[1]) break;
						if(x2<minn[1]+1) break;
						if(x3+maxn[2]>w[2]) break;
						if(x3<minn[2]+1) break;
						x1+=last[0];
						x2+=last[1];
						x3+=last[2];
					}
					int step=0;
					for(;step<n;step++){
						x1+=d[step];
						if(x1>w[0]) break;
						if(x1<0) break;
						if(x2>w[2]) break;
						if(x2<0) break;
						if(x3>w[2]) break;
						if(x3<0) break;
					}
					ans+=round*n+step;
				}
			}
		}
	}
	printf("%d\n",ans);
}

int main(){
	freopen("walk.in","r",stdin);
	froepen("walk.out","w",stdout);
	Input();
	Init();
	Solve();
	return 0;
}
