#include<bits/stdc++.h>
#define mod 1000000007
#define maxn 500005
#define maxk 15
using namespace std;
template<typename TP>
inline void read(TP &num7){
	long long val7=0;int w7=1;
	char ch7=getchar();
	while(ch7<'0'||ch7>'9'){if(ch7=='-')w7=-1;ch7=getchar();}
	while(ch7>='0'&&ch7<='9'){val7=(val7<<3)+(val7<<1)+ch7-'0';ch7=getchar();}
	num7=val7*w7;
}
int n,k;
long long w[maxk];
int c[maxn],d[maxn];
int xyz[maxk];bool flag=0;
int txyz[maxk];
long long ans=0;
void work(){
	int i;
	for(i=1;i<=k;i++)
	txyz[i]=xyz[i];
	bool flag1=1;
	for(i=1;i<=n;i++){
		txyz[c[i]]+=d[i];
		if(txyz[c[i]]>w[c[i]]||txyz[c[i]]<1)
		flag1=0;
	}
	for(i=1;i<=k;i++)if(txyz[i]!=xyz[i])flag1=0;
	if(flag1){
		flag=1;
		return;
	}
	for(i=1;i<=k;i++)
	txyz[i]=xyz[i];
	while(1){
		for(i=1;i<=n;i++){
			txyz[c[i]]+=d[i];
			ans++;
			if(txyz[c[i]]>w[c[i]]||txyz[c[i]]<1)return;
		}
		ans%=mod;
	}
}
void dfs(int D){
	int i;
	if(flag==1)return;
	if(D==k+1){
		work();
		return;
	}
	for(i=1;i<=w[D];i++){
		xyz[D]=i;
		if(!flag)
		dfs(D+1);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	read(n);read(k);
	int i;
	for(i=1;i<=k;i++)read(w[i]);
	for(i=1;i<=n;i++)read(c[i]),read(d[i]);
	dfs(1);
	if(flag){
		puts("-1");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	cout<<ans%mod;
}
