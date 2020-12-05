#include<bits/stdc++.h>
using namespace std;
#define reg register
typedef long long ll;
const int N=5e5+5,P=1e9+7;
inline int read(){
	int x=0,f=1;char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') f=0;
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?x:-x;
}
int n,k,w[15],p[15];
bool flag;
ll tot[15],ans,mx[15],mn[15],num1[15],num2[15],pos[15];
ll culc(){
	ll res=N;
	for(reg int i=1;i<=k;i++){
		if(p[i]+mx[i]>w[i]) res=min(res,num1[i]);
		else if(p[i]+mn[i]<1) res=min(res,num2[i]);
	}
	return res;
}
ll work(){
	for(reg int i=1;i<=k;i++) p[i]=pos[i];
	ll sum=culc(),res=0;
	if(sum!=N) return sum;
	for(reg int i=1;i<=k;i++){
		if(tot[i]>0) sum=min(sum,(w[i]-pos[i])/tot[i]);
		else if(tot[i]<0) sum=min(sum,pos[i]/((-1)*tot[i]));
	}
	for(reg int i=1;i<=k;i++) p[i]=pos[i]+tot[i]*n;
	res=sum*n+culc();
	return res;
}
void dfs(){
	ans=(ans+work())%P;
	for(reg int i=1;i<=k;i++){
		if(pos[i]<w[i]){
			pos[i]++;dfs();pos[i]--;
		}
	}
}
int main()
{
	freopen("walk.in","r",stdin);freopen("walk.out","w",stdout);
	n=read(),k=read();int a,b;
	for(reg int i=1;i<=k;i++) w[i]=read();
	for(reg int i=1;i<=n;i++){
		a=read(),b=read();
		tot[a]+=b;
		if(tot[a]>mx[a])
			mx[a]=tot[a],num1[a]=i;
		if(tot[a]<mn[a])
			mn[a]=tot[a],num2[a]=i;
	}
	for(reg int i=1;i<=k;i++) pos[i]=1;
	dfs();
	printf("%lld",ans);
	return 0;
}
