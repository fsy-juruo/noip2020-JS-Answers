#include<bits/stdc++.h>
using namespace std;
const int N=200010;

int n,k;
int w[N],c[N],d[N];
int l[N],r[N],e[N],ta[N],a[N];
long long ans;
int modd=1000000007;

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

bool check(){
	for (int i=1;i<=k;i++){
		if (a[i]+l[i]<=0||a[i]+r[i]>w[i]) return 0;
	}
	return 1;
}

void print(){
	while (check()){
		for (int i=1;i<=k;i++) a[i]+=e[i];
		ans+=n; ans%=modd;
	}
	for (int i=1;i<=n;i++){
		a[c[i]]+=d[i]; ans++; ans%=modd;
		if (a[c[i]]<=0||a[c[i]]>w[c[i]]) break;
	}
}

void work(int dep){
	if (dep>k) {for (int i=1;i<=k;i++) a[i]=ta[i]; print(); return;}
	for (int i=1;i<=w[dep];i++){
		ta[dep]=i; work(dep+1);
	}
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(); k=read();
	for (int i=1;i<=k;i++) w[i]=read();
	for (int i=1;i<=n;i++){
		l[i]=1000000000; r[i]=-1000000000;
	}
	for (int i=1;i<=n;i++){
		c[i]=read(); d[i]=read();
		e[c[i]]+=d[i]; 
		l[c[i]]=min(l[c[i]],e[c[i]]); r[c[i]]=max(r[c[i]],e[c[i]]);
	}
	int fl=1;
	for (int i=1;i<=k;i++)
		if (e[i]!=0) {fl=0; break;}
	if (fl==1) {cout<<-1<<endl; return 0;}
	ans=0;
	work(1);
	cout<<ans<<endl;
	return 0;
}

