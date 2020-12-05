#include<bits/stdc++.h>
using namespace std;
const int M=5e5+7;
const int mod=1e9+7,mod1=500003;
long long n,k,sum,ans,w[15],pos[15],c[M],d[M],f[600000],base=107,spedup[600000];
bool flag=true;

inline int read(){
	char ch;
	int x=0,f=1;
	ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}

inline void search(){
	while(true){
		for(int i=1;i<=n;i++){
			pos[c[i]]+=d[i];
			sum++;
			if(pos[c[i]]<1||pos[c[i]]>w[c[i]]) return;
		}
		int x=0;
		for(int i=1;i<=k;i++)
			x=(x*base%mod1+pos[i])%mod1;
		if(spedup[x]){sum+=spedup[x]; return;}
		if(f[x]){sum=-1; return;}
		else f[x]=1;
	}
}

inline void _status(int t){
	if(t==k+1){
		sum=0;
		memset(f,0,sizeof(f));
		int tran[12];
		for(int i=1;i<=k;i++) tran[i]=pos[i];
		int x=0;
		for(int i=1;i<=k;i++)
			x=(x*base%mod1+pos[i])%mod1;
		f[x]=1;
		search();
		if(sum==-1) {flag=false; ans=-1; return;}
		ans=(ans+sum)%mod;
		spedup[x]=sum;
		for(int i=1;i<=k;i++) pos[i]=tran[i];
		return;
	}
	for(int i=1;i<=w[t]&&flag;i++){
		pos[t]=i;
		_status(t+1);
	}
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(); k=read();
	for(int i=1;i<=k;i++) w[i]=read();
	for(int i=1;i<=n;i++) c[i]=read(),d[i]=read();
	_status(1);
	cout<<ans<<endl;
	return 0;
}

