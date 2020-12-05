#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5,MOD=1e9+7;
int n,k,T;
int w[11];
int move[N],dir[N];
int now[N];
int ans=0;
pair<int,int> a[N];
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
void dg(int d){
	if(d==k+1){
		int tmp[11];
		for(int i=1;i<=k;++i){
			tmp[i]=now[i];
		}
		for(int i=1;i<=n;++i){
			ans=(ans+1)%MOD;
			int kk=move[i];
			tmp[kk]+=dir[i];
			if(tmp[kk]==0||tmp[kk]==w[kk]+1)break;
			if(i==n)i=0;
		}
	}
	for(int i=1;i<=w[d];++i){
		now[d]=i;
		dg(d+1);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(),k=read();
	if(n<=100){
		for(int i=1;i<=k;++i)w[i]=read();
		for(int i=1;i<=n;++i)move[i]=read(),dir[i]=read();
		dg(1);
		cout<<ans<<endl;
	}
	else {
		cout<<"-1"<<endl;	
	}
	return 0;
}
/*
3 1
5
1 1
1 1 
1 -1

*/
