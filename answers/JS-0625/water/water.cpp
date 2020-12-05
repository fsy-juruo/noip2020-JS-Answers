#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int out[N],tt=0;
ll fz[N],fm[N];
int connect[N][6],m,n;
int b[N],ttt=0,ru[N];
ll gcd(ll x,ll y){
	if(y==0)return x;
	return gcd(y,x%y);
}
ll gbs(ll x,ll y){
	return x*y/gcd(x,y);
}
void add(int fz1,int fm1,int fz2,int fm2){
	ll tmp=gbs(fm[fm1],fm2);
	fz[fz1]=fz[fz1]*tmp/fm[fm1]+fz2*tmp/fm2;
	fm[fm1]=tmp;
	int chu=gcd(fz[fz1],fm[fm1]);
	fz[fz1]/=chu;
	fm[fm1]/=chu;
}
int read(){
	int p=0,q=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')q=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		p=p*10+ch-'0';
		ch=getchar();
	}
	return p*q;
}
void solve(int x){
	if(fz[x]==0)return;
	for(int i=1;i<=connect[x][0];++i){
		int Ver=connect[x][i];
		add(Ver,Ver,fz[x],fm[x]*connect[x][0]);
	}
}
int q[N],h=0,r=0;
void topsort(){
	int tmp=0;
	for(int i=1;i<=n;++i)if(ru[i]==0&&connect[i][0]!=0)q[++r]=i,b[++ttt]=i;
	while(h<r){
		int t=q[++h];
		for(int i=1;i<=connect[t][0];++i){
			int Ver=connect[t][i];
			ru[Ver]--;
			if(ru[Ver]==0&&connect[Ver][0]!=0){
				q[++r]=Ver;
				b[++ttt]=Ver;	
			}
		}
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;++i)fz[i]=1;
	for(int i=1;i<=n;++i)fm[i]=1;
	for(int i=1;i<=n;++i){
		int num=read();
		if(num==0)out[++tt]=i;
		else {
			connect[i][0]=num;
			for(int j=1;j<=num;++j){
				connect[i][j]=read();
				ru[connect[i][j]]++;	
			}
		}
	}
	topsort();
	for(int i=1;i<=ttt;++i)solve(b[i]);
	for(int i=1;i<=tt;++i){
		printf("%d ",fz[out[i]],fm[out[i]]);
		printf("%d\n",fm[out[i]]);
	}
	return 0;
}

