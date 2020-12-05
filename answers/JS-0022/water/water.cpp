#include<bits/stdc++.h>
using namespace std;
const int N=200010;

int n,m;
int du[N],chu[N],now[N];
long long p[N],q[N];
int a[N][10];

int read(){
	int x=0,f=1; char ch;
	while (ch>'9'||ch<'0'){
		  if (ch=='-') f=-1;
		  ch=getchar();
	}
	while (ch>='0'&&ch<='9'){
		  x=(x<<3)+(x<<1)+ch-'0';
		  ch=getchar();
	}
	return x*f;
}

long long gd(long long x,long long y){
	if (x<y) swap(x,y);
	if (x%y==0) return y; else return gd(y,x%y);
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(); m=read();
	for (int i=1;i<=n;i++){
		chu[i]=read();
		for (int j=1;j<=chu[i];j++){
			a[i][j]=read(); du[a[i][j]]++;
		}
	}
	int l=1,r=0;
	for (int i=1;i<=n;i++){
		if (du[i]==0) {r++; now[r]=i; p[i]=1; q[i]=1;}
	}
	while (l<=r){
		for (int i=1;i<=chu[now[l]];i++){
			int t=a[now[l]][i];
			du[t]--;
			if (p[t]==0&&q[t]==0) {p[t]=p[now[l]]; q[t]=(long long)(q[now[l]]*chu[now[l]]);}
				else {
					p[t]*=q[now[l]]; p[t]*=chu[now[l]]; p[t]+=p[now[l]]*q[t]; 
					q[t]*=q[now[l]]; q[t]*=chu[now[l]];
				}
			long long g=gd(p[t],q[t]); p[t]/=g; q[t]/=g;
			if (du[t]==0) {r++; now[r]=t;} 
		}
		l++;
	}
	for (int i=1;i<=n;i++)
		if (chu[i]==0) cout<<p[i]<<' '<<q[i]<<endl;
	return 0;
}

