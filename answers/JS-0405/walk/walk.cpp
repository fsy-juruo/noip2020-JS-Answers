#include <bits/stdc++.h>
#define intinf 2147483647
#define mod 1000000007
#define MAXN 500005
#define MAXK 13
using namespace std;
inline int read(){
	int num=0,zf=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')zf=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar();
	}
	return zf*num;
}
int n,k;
int w[MAXK];
int c[MAXN],d[MAXN];
int start[MAXK],now[MAXK],eve[MAXK],cei[MAXK],flo[MAXK];
long long ans;
void posi(){
	start[1]++;
	int h=1;
	while(start[h]>w[h]){
		start[h]=1;
		start[++h]++;
		if(h==k+1)break;
	}
	if(h==k+1){
		printf("%lld\n",ans%mod);
		exit(0);
	}
	for(int i=1;i<=k;i++)
		now[i]=start[i];
	return ;
}
bool ok;
int ti(){
	for(int i=1;i<=k;i++){
		//cout<<now[i]<<' '<<cei[i]<<' '<<flo[i]<<endl;
		if(now[i]+cei[i]>w[i])return 0;
		if(now[i]+flo[i]<1)return 0;
	}//cout<<"!";
	if(ok==1){
		printf("-1\n");
		exit(0);
	}
	int h=intinf;
	for(int i=1;i<=k;i++){
		//cout<<eve[i]<<' ';
		if(eve[i]>0){
			h=min(h,(w[i]-cei[i]-now[i])/eve[i]);
			//cout<<w[i]<<' '<<cei[i]<<' '<<now[i]<<' '<<eve[i]<<endl;
		}
		if(eve[i]<0){
			h=min(h,-(now[i]+flo[i]-1)/eve[i]);
		}
		
	}
	return h;
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	ok=1;
	n=read();k=read();
	for(int i=1;i<=k;i++)w[i]=read(),start[i]=1;
	for(int i=1;i<=n;i++){
		c[i]=read();
		d[i]=read();
		eve[c[i]]+=d[i];
		cei[c[i]]=max(cei[c[i]],eve[c[i]]);
		flo[c[i]]=min(flo[c[i]],eve[c[i]]);
	}
	for(int i=1;i<=k;i++)if(eve[i])ok=0;
	start[1]=0;int cnt=0;
	while(1){
		posi();
		int h=ti();
		for(int i=1;i<=k;i++){
			now[i]+=h*eve[i];
		}
		ans+=(n*h%mod);ans%=mod;
		int aa=0;
		while(1){
			cnt++;
			aa++;aa%=(n+1);if(aa==0)aa=1;
			now[c[aa]]+=d[aa];ans++;
			if(now[c[aa]]>w[c[aa]]||now[c[aa]]<1)break;
		}
		ans%=mod;
	}
	return 0;
}
