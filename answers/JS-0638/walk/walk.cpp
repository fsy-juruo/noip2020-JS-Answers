#include<bits/stdc++.h>
using namespace std;

void fre() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
}

typedef long long ll;

inline ll read() {
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void write(ll x) {
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}

ll n,k;
ll w[15];
ll c[500500],d[500500];

struct Node {
	ll coor[15];
	Node() {}
	Node(ll cood) {
		for(ll i=k; i>=1; i--) {
			coor[i]=cood%w[i]+1;
			cood/=w[i];
		}
	}
	ll calc() {
		ll ans=0;
		for(ll i=1; i<=k; i++) {
			ans=ans*w[i];
			ans+=coor[i]-1;
		}
		return ans;
	}
} temp;

ll ans=0;
void calculate() {
	Node index=temp;
	for(ll i=1;; i++) {
		ll t=(i-1)%n+1;
		index.coor[c[t]]+=d[t];
		if(index.coor[c[t]]<=0||index.coor[c[t]]>w[c[t]]) {
			ans+=i;
			return;
		}
	}
}
void dfs(ll di) {
	if(di==k+1) {
		calculate();
		return;
	}
	for(ll i=1; i<=w[di]; i++) {
		temp.coor[di]=i;
		dfs(di+1);
	}
}

signed main() {
	fre();

	n=read(),k=read();
	for(ll i=1; i<=k; i++)w[i]=read();
	for(ll i=1; i<=n; i++)c[i]=read(),d[i]=read();

	ll sum[15]= {};
	ll maxn[15]= {},minn[15]= {};
	for(ll i=1; i<=n; i++) {
		sum[c[i]]+=d[i];
		maxn[c[i]]=max(maxn[c[i]],d[i]);
		minn[c[i]]=min(minn[c[i]],d[i]);
	}
	
	bool flag=true;
	for(ll i=1; i<=k; i++)
		if(!(sum[i]==0&&maxn[i]-minn[i]<w[i]))flag=false;
	if(flag) {
		cout<<-1<<endl;
		return 0;
	}
	
	dfs(1);
	write(ans);

	return 0;
}
